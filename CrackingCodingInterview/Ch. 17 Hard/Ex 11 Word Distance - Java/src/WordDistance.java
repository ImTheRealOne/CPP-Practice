/**
 * 
 */

/**
 * @author ImTheRealOne
 * 
 * Word Distance: You have a large text file containing words. Given any two words, find the shortest
distance (in terms of number of words) between them in the file. If the operation will be repeated
many times for the same file (but different pairs of words), can you optimize your solution?
 *
 */
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.lang.reflect.Array;
import java.net.URL;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Scanner;
import java.util.Map.Entry; 
public class WordDistance {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		final String FILENAME = "words.txt";
		HashMap<String, ArrayList<Integer>> wordLocation = createHashMap(FILENAME);
		printhashMap(wordLocation);
		
		System.out.println(shortestDistance(wordLocation, "asdf", "as"));		
		System.exit(0);
	}
	
	public static void printhashMap(HashMap<String, ArrayList<Integer>> hashMap) {
		Iterator mapIt = hashMap.entrySet().iterator();
		
		while(mapIt.hasNext()) {
			Entry<String, ArrayList<Integer>> entry = (Entry<String, ArrayList<Integer>>) mapIt.next();
			System.out.println(entry.getKey() + " : " + entry.getValue().toString());
		}
		
		
	}
	//using the hashmap with word locations stored you ccompare locations
	public static int shortestDistance( HashMap<String, ArrayList<Integer>> wordLocations ,
			String word1, String word2) {
		
		int distance = Integer.MAX_VALUE;
		ArrayList<Integer> list1 = wordLocations.get(word1);
		ArrayList<Integer> list2 = wordLocations.get(word2);
		if(list1 != null && list2 != null) {
			System.out.println(list1.toString());
			System.out.println(list2.toString());
			int list1Index = 0;
			int list2Index = 0;
			int difference = -1;
			boolean updated = true;
			//iterate the two and get the smallest difference
			while(updated && (list1Index < list1.size() || list2Index < list2.size())) {
				//update is set as false to check if the indexes moved
				updated = false;
				difference = Math.abs(list1.get(list1Index) - list2.get(list2Index));
				if(difference < distance) {
					distance = difference;
				}
				//move the smaller element of the two list
				if(list1Index < list1.size()-1 && list1.get(list1Index) >= list2.get(list2Index)) {
					list1Index++;
					updated = true;
				}
				else {
					if(list2Index < list2.size()-1) {						
						list2Index++;
						updated = true;
					}
				}
				
			}
			
		}
		
		return distance;
	}
	
	//read the file then scan each words and add its word count to its list
	public static HashMap<String, ArrayList<Integer>> createHashMap(String fileName){
		HashMap<String, ArrayList<Integer>> hashMap = new HashMap<>();
		
		Scanner lineScanner = null;
		
		try {
			lineScanner = new Scanner(new File(fileName));
		}catch (FileNotFoundException e) {
			// TODO: handle exception
			e.printStackTrace();
		}
		int wordCount = 0;
		while(lineScanner.hasNextLine()) {
			Scanner wordScanner = new Scanner(lineScanner.nextLine());
			while (wordScanner.hasNext()) {
				String word = wordScanner.next();
				//sanitize the word erasing all punctuation
				word = word.replaceAll("[\\W]", "");
				word = word.toLowerCase();
				wordCount++;
				//if word isn't inside the map add a new arraylist with its word count
				if(!hashMap.containsKey(word)) {
					hashMap.put(word,new ArrayList<>(Arrays.asList(wordCount)));
				}
				else {
					hashMap.get(word).add(wordCount);
				}
				
			}
		}
		
		return hashMap;
	}

}
