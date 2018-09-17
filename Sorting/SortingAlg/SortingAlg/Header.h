#pragma once
#ifndef HEADER_H
#define HEADER_H

/*
	class ; sortAbstract 
	purpose : abstract class for sorting algorithms

*/
#include "sortAbstract.h"

/*
	class ; bubbleSort
	purpose : inherited class for bubble sort from sort abstract class
	algorithm : compare each individual elements starting at index 0 and swapping adjacent elements if they are in wrong order. If we do this n * n times it'll eventuall be in order.

	best runtime : O(n)
	average runtime : O(n^2)
	worst runtime : O(n^2)

*/

#include "bubbleSort.h"

/*
	class : insertionSort  
	purpose : inherited class for insertion sort from sort abstract class
	algorithm : starting at an index shift all element smaller or greater to left or right direction then do that for all elements

	best runtime : O(n)
	average runtime : O(n^2)
	worst runtime: O(n^2)

*/

#include "insertionSort.h"


/*
	class : QuickSort
	purpose : inherited class for quick sort from sort abstract class
	algorithm : using a divide and conquer approach divide the array into sub arrays about a pivot. Then the arrray will slowly sort about the pivot making all element greater or less than itself on one end

	best runtime : O(n log (n))
	average runtime : O(n log (n))
	worst runtime: O(n^2)

*/

#include "QuickSort.h"

/*
	class : BinSort
	purpose : inherited class for bin sort from sort abstract class
	algorithm : put data into bins before calling insertion sort on the individual then adding all elements from each bin in order

	best runtime : 

*/

#include "BinSort.h"

#include "MergeSort.h"


#include <random>

#include <iostream>




#endif // !HEADER_H

/*
	class : 
	purpose :
	algorithm :

	best runtime :
	average runtime :
	worst runtime:

*/