/**
 * 
 */

/**
 * @author ImTheRealOne
 * 
 * Smallest K: Design an algorithm to find the smallest K numbers in an array.
Hints: #470, #530, #552, #593, #625, #647, #661, #678
 *
 *
 *Solution : use a priority queue implemented through an arraylist to read and check versus current items inside
 *				the queue 
 *
 *			
 */
public class SmallestKNumbers {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

		int k = 5;
		
		
		int arr [] = {5,3,65,7,5,34,7,54,9,3,9,1,2,3};
		int smallest [] = getKSmallest(arr,5 );
		print(smallest);
		
		System.out.println("done");
		System.exit(0);
	}
	
	public static void print(int [] arr) {
		for(int i = 0; i < arr.length; i++) {
			System.out.print(arr[i] + "  " );
		}
		System.out.println();
	}
	//return the k smallest element
	public static int[] getKSmallest(int [] arr, int k){
		int [] smallestArray = new int [k];
		PriorityQueue<Integer> priorityQueue = new PriorityQueue<>(k);
		for(int i = 0; i < arr.length; i++) {
			priorityQueue.add(arr[i]);
		}
		
		for(int i = 0; i < priorityQueue.size(); i++) {
			if(priorityQueue.getAt(i) != null) {
				smallestArray[i] = priorityQueue.getAt(i);				
			}
		}
		
		
		return smallestArray;
		
		
	}

}
