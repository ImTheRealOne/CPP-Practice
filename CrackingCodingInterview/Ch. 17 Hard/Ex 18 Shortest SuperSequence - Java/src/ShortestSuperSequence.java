import java.util.ArrayList;
import java.util.HashMap;

/**
 * 
 */

/**
 * @author ImTheRealOne
 * 
 * Shortest Supersequence: You are given two arrays, one shorter (with all distinct elements) and one
longer. Find the shortest subarray in the longer array that contains all the elements in the shorter
array. The items can appear in any order.
EXAMPLE
Input: {1, 5, 9} I {7, 5, 9, 13, 2, 1, 3, 5, 7, 9, 1, 1, 5, 8, 8, 9, 7}
Output: [7, 113] (the underlined portion above)
 *
 *
 *Solution : 1) Find all indexes for each unique elements and store them into a
 *				ArrayList using hashmap
 *			2) get the arrayList needed from small array
 *			3) iterate from index 0 to length of the longest array to calculate
 *				shortest sequence
 *				a) if your current index is larger than the smallest index of any
 *					key element remove such index to get the next index 
 *				3) if any time the difference between the largest and smallest index
 *					containing all key element is smaller than your last smallest
 *						update
 */
public class ShortestSuperSequence {
	//class to return an index pair 
	public static class PairIndex {
		int lowerBound;
		int upperBound;
		public PairIndex() {
			upperBound = 0;
			lowerBound = 0;
		}
		public PairIndex(int x, int y){
			if(x > y) {
				upperBound = x;
				lowerBound = y;
			}
			else {
				lowerBound = x;
				upperBound = y;
			}
		}
		
		public int getLower () {
			return lowerBound;
		}
		public int getUpper() {
			return upperBound;
		}
		public void setLower(int newLower) {
			lowerBound = newLower;
		}
		public void setUpper(int newUpper) {
			upperBound = newUpper;
		}
		
		@Override
		public String toString() {
			return "["+lowerBound+","+upperBound+"] : " + (upperBound-lowerBound); 
		}
	};
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

		int sequence [] = {7,5,9,13,2,1,3,5,7,9,1,1,5,8,8,9,7};
		int input [] = {1,5,9};
		ShortestSuperSequence.PairIndex pairIndex = null;
		
		HashMap<Integer, ArrayList<Integer>> numberPlacements = countOfInstances(input, sequence);

		System.out.println(numberPlacements.toString());
		pairIndex = slidingWindow(numberPlacements, input, sequence);
		System.out.println(pairIndex);
	}
	//find the indexes of each element in the array and up them into an ArrayList
	public static HashMap<Integer, ArrayList<Integer>> countOfInstances(int input [], int sequence []){
		HashMap<Integer, ArrayList<Integer>> map = new HashMap<>();
		for(int i = 0 ; i < sequence.length;i++) {
			//if the element isn't in the hashmap create a new array
			if(!map.containsKey(sequence[i])) {
				ArrayList<Integer> arrayList  = new ArrayList<>();
				arrayList.add(i);
				map.put(sequence[i], arrayList);
			}
			//if element is in the hashmap just add to the array
			else {
				map.get(sequence[i]).add(i);
			}
		}
		
		
		return map;
	}
	//find the smallest supersequence
	public static ShortestSuperSequence.PairIndex slidingWindow(HashMap<Integer, ArrayList<Integer>> hashMap , int input [], int sequence []) {
		PairIndex indexes = null;
		ArrayList<ArrayList<Integer>> instancesOfNums= new ArrayList<>();
		//get all key elements' index locations
		for(int i = 0; i < input.length; i++) {
			instancesOfNums.add(hashMap.get(input[i]));
		}
		System.out.println(instancesOfNums.toString());
		
		int minIndex = Integer.MAX_VALUE;
		int maxIndex = Integer.MIN_VALUE;
		int difference = Integer.MAX_VALUE;
		//iterate through the long array length
		for(int i=  0; i < sequence.length;i++) {
			//iterate through the head of each key element index arrayList
			for(int j = 0; j < instancesOfNums.size();j++) {
				//there is at least one element in key element index arrayList
				if(instancesOfNums.get(j).size() > 0) {
					//if indexes is greater than the smallest occurrence of key element
					if(instancesOfNums.get(j).get(0) < i) {
						//if the key element occurs again in the long array
						if(instancesOfNums.get(j).size() > 1 ) {
							//remove the smallest occurrence to get next occurrence
							instancesOfNums.get(j).remove(0);
						}
						
					}
				}
				//get the largest and smallest indexes of the key elements
				if(minIndex > instancesOfNums.get(j).get(0)) {
					minIndex = instancesOfNums.get(j).get(0);
				}
				if(maxIndex < instancesOfNums.get(j).get(0)) {
					maxIndex = instancesOfNums.get(j).get(0);
				}
				
				
			}
			//check if the the new difference is smaller than the last known smallest
			if(minIndex != maxIndex && difference > maxIndex-minIndex) {
				difference = maxIndex-minIndex;
				indexes = new PairIndex(minIndex,maxIndex);
			}
			//reset values
			minIndex = Integer.MAX_VALUE;
			maxIndex = Integer.MIN_VALUE;
		}
		
		
		
		return indexes;
	}
	
	

}


