import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.PriorityQueue;
import java.util.Random;
import java.util.function.DoubleToIntFunction;

/**
 * 
 */

/**
 * @author ImTheRealOne
 * 
 * Continuous Median: Numbers are randomly generated and passed to a method. Write a program
to find and maintain the median value as new values are generated.
 *
 *Solution : 
 *
 */
public class ContinuousMedianMain {

	static class QueueContainer {
		
		PriorityQueue<Integer> maxQueue;
		PriorityQueue<Integer> minQueue;
		
		public QueueContainer() {
			// TODO Auto-generated constructor stub
			maxQueue = new PriorityQueue<>(Collections.reverseOrder());
			minQueue = new PriorityQueue<>();
		}
		
		public void add(int num) {
			//both queues empty add to left
			if(maxQueue.isEmpty() && minQueue.isEmpty()) {
				maxQueue.add(num);
			}
			else {
				//num is smaller than left queue biggest
				if(num <= maxQueue.peek()) {
					maxQueue.add(num);
				}
				else {
					minQueue.add(num);
				}
						
			}
			rebalance();
		}
		
		public void rebalance() {
			//difference between the two queue is greater than 1
			//need to shift an element
			if(Math.abs(maxQueue.size() - minQueue.size()) > 1) {
				if(maxQueue.size() > minQueue.size()) {
					Integer maxQueueElement = maxQueue.poll();
					minQueue.add(maxQueueElement);
				}
				else {
					Integer minQueueElement = minQueue.poll();
					maxQueue.add(minQueueElement);
				}
			}
			
		}
		public Double getMedian() {
			int median = 0;
			//if both are empty return null
			if(maxQueue.isEmpty() && minQueue.isEmpty()) {
				return null;
			}
			//if left side empty and right side is not
			//return right side median probably at index 0
			if(maxQueue.isEmpty()) {
		
				return new Double( minQueue.peek());
			}
			//if right side empty and left side is not
			//return left side median probably at index 0
			if(minQueue.isEmpty()) {
				return new Double(maxQueue.peek());
			}
			//if no empty arraylist then check to see which side is bigger
			//if left side bigger then return max of left side
			if(maxQueue.size() > minQueue.size()) {
				return new Double( maxQueue.peek());
			}
			//if right side bigger return min of right side 
			else if (maxQueue.size() < minQueue.size()) {
				return new Double( minQueue.peek());
			}
			//if equal sizes then get the medium of the to peeks
			else {
				return new Double(maxQueue.peek()+ minQueue.peek())/2;
			}	
		}
		
		
		@Override
		public String toString() {
			return maxQueue.toString() + " : " + minQueue.toString();
		}
	}

	
	public static void main(String[] args) {
		/*// TODO Auto-generated method stub
		PriorityQueue<Integer> maxQueue = new PriorityQueue<>(Collections.reverseOrder());
		PriorityQueue<Integer> minQueue = new PriorityQueue<>();
		
		Integer arr[] = {5,9,3,6,1,7};
		minQueue.addAll(Arrays.asList(arr));
		System.out.println("minQ : " + minQueue.toString());
		maxQueue.addAll(Arrays.asList(arr));
		System.out.println("maxQ : " + maxQueue.toString());
		*/
		
		ContinuousMedianMain.QueueContainer queueContainer = new ContinuousMedianMain.QueueContainer();
		
		int arr[] = {1,9,11,4,5,6};
		
		for(int i = 0; i < arr.length; i++) {
			queueContainer.add(arr[i]);
			System.out.println(queueContainer.toString());
			System.out.println(queueContainer.getMedian());
		}
		
	}
	
	public static Integer getRandomNumber() {
		Random random = new Random();
		Integer randomNumber = random.nextInt(20);
		System.out.println("Next random Int : " + randomNumber);
		return randomNumber;
	}
	
	
	
	
	
	

}
