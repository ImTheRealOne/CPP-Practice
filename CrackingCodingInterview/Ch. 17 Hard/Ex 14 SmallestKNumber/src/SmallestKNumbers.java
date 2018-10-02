/**
 * 
 */

/**
 * @author ImTheRealOne
 *
 */
public class SmallestKNumbers {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

		int k = 5;
		
		PriorityQueue<Integer> priorityQueue = new PriorityQueue<>(k);
		
		priorityQueue.add(5);
		priorityQueue.add(14);
		priorityQueue.add(9);
		
		priorityQueue.print();
		
		
		System.exit(0);
	}

}
