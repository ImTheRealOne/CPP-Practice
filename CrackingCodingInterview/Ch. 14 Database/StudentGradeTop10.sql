/*	prepare stmt from 'select avg(grade) as g from grades group by student_ID order by  g desc limit ?';
(select count(*) into @percentile from student);
   select @percentile * .1 into @test;
   

   execute stmt using @test;
   
   
   (SELECT 
    COUNT(*)
INTO @percentile FROM
    student);
SELECT @percentile * .1 INTO @test;
   
   
	SELECT 
    *
FROM
    (SELECT 
        a.*, @rowrank:=@rowrank + 1 AS rank
    FROM
        (SELECT 
        AVG(grade) AS avg_grade
    FROM
        grades
    GROUP BY Student_ID
    ORDER BY avg_grade DESC) a, (SELECT @rowrank:=0) r) d
WHERE
    rank < @test;
    
    1,2,3,4,5,67,8,9,02
   */

#get top 10 percent index
SELECT 
    ((90 / 100) * (COUNT(student_ID) + 1))
INTO @index FROM
    student;

SELECT @index;

#get cutoff gpa value
SELECT 
    AVG(avg_grade)
INTO @top10value FROM
    (SELECT 
        a.*, @rowrank:=@rowrank + 1 AS rank
    FROM
        (SELECT 
        AVG(grade) AS avg_grade
    FROM
        grades
    GROUP BY Student_ID
    ORDER BY avg_grade ASC) a, (SELECT @rowrank:=0) r) d
WHERE
    rank = FLOOR(@index)
        OR rank = CEILING(@index);
    
SELECT @top10value;

#get all students;
SELECT 
    student_ID, AVG(grade) avg_grade
FROM
    grades
GROUP BY student_ID
HAVING avg_grade >= @top10value;