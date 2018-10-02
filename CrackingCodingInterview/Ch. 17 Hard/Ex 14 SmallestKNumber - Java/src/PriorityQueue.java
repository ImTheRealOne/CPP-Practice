import java.util.ArrayList;import org.omg.PortableInterceptor.IORInterceptor;

public class PriorityQueue <T extends Comparable<T>> {
	private ArrayList<T> queue;
	private int maxSize;
	
	public PriorityQueue(int size) {
		// TODO Auto-generated constructor stub
		queue = new ArrayList<>();
		maxSize = size;
	}
	
	public int size() {
		return queue.size();
	}
	
	public T getAt(int index) {
		if(index < queue.size()) {
			return queue.get(index);
		}
		
		return null;
	}
	
	//add compare elements inside the arraylist to the new entry 
	public void add(T newData) {
		boolean added = false;
		if(queue.isEmpty()) {
			queue.add(newData);
			return;
		}
		//compare each element to insert into a proper index
		//for loop doesn't check last element
		for(int i = 0; i < queue.size();i++) {
			System.out.print(queue.get(i) + "  ");
			if(!added && queue.get(i).compareTo(newData) > 0) {
				added = true;
				queue.add(i, newData);
				i++;
			}
		}
		System.out.println();
		//if element hasn't been added check if queue is smaller than max size
		//if queue size bigger than max remove the last added element 
		if(!added && queue.size() < maxSize) {
				queue.add(queue.size()-1, newData);
		}
		if(queue.size() > maxSize) {
			System.out.println("never runs ");
			queue.remove(queue.size()-1);
		}
		
	}
	
	public void print() {
		for(int i = 0; i < queue.size();i++) {
			System.out.print(queue.get(i)+ "  " );
		}
		System.out.println();
	}
}
