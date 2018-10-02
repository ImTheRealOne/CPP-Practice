import java.util.ArrayList;import org.omg.PortableInterceptor.IORInterceptor;

public class PriorityQueue <T extends Comparable<T>> {
	private ArrayList<T> queue;
	private int maxSize;
	
	public PriorityQueue(int size) {
		// TODO Auto-generated constructor stub
		queue = new ArrayList<>();
		maxSize = size;
	}
	
	
	public void add(T newData) {
		if(queue.isEmpty()) {
			queue.add(newData);
		}
		for(int i = 0; i < queue.size();i++) {
			if(queue.get(i).compareTo(newData) <= 0) {
				queue.add(i, newData);
			}
		}
		if(queue.size() > maxSize) {
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
