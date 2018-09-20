import java.util.ArrayList;

/**
 * 
 */

/**
 * @author ImTheRealOne
 * Majority Element: A majority element is an element that makes up more than half of the items in
an array. Given a positive integers array, find the majority element. If there is no majority element,
return -1. Do this in 0 (N) time and O( 1) space.
EXAMPLE
Input: 1 2 5 9 5 9 5 5 5
Output: 5
 *
 */
public class MajorityElement {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

		int arr [] = {1,2,5,9,5,9,5,5,5};
		int arr2 [] = {3,1,7,1,3,7,3,7,1,7,7,7};
		int arr3 [] = {1,1,2,3,2,1};
		System.out.println(getMajorityElementBrute(arr3));
		System.out.println(majorityElementOptimal(arr3));
		
		System.exit(0);
	}
	
	//double for loop to process the numbers
	public static int getMajorityElementBrute(int [] arr) {
		int result = -1;
		ArrayList<Integer> processedNums = new ArrayList<>();
		int minMajorityCount = (arr.length/2);
		if(arr.length > 0) {
			int currElement;
			currElement = arr[0]; 
			int currCount = 1;
			for(int i = 1; i < arr.length;i++) {
				
				for(int j = i; j<arr.length; j++) {
					if(arr[j] == currElement) { 
						currCount++;
					}
					if(currCount > minMajorityCount) {
						return arr[j];
					}
					
					
				}
				currElement = arr[i];
				currCount = 1;;
			}
		
			
			
		}
		
		
		return result;
	}
	//optimal solution O(N) time and O(1) space
	//find the number that appears most relative to all surrounding number
	//if that number is a majority 
	public static int majorityElementOptimal(int [] arr) {

		if(arr.length < 0) {
			return -1;
		}
		int currElement = -1;
		int currCount = 0;
		for(int i = 0; i < arr.length; i++) {
			if(currCount <= 0) {
				currElement = arr[i];
			}
			if(currElement == arr[i]) {
				currCount++;
			}
			else {
				currCount--;
			}
			
			
			
		}
		
		
		currCount = 0;
		for(int i =0; i < arr.length; i++) {
			if(arr[i] == currElement ) {
				currCount++;
			}
		}
		
		
		return (currCount > arr.length /2) ? currElement : -1;
	}

}
