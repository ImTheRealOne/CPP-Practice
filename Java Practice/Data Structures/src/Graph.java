
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map.Entry;


public class Graph<T> {
	
	private HashMap<T, Node<T>> nodeList;
	
	public Graph() {
		nodeList = new HashMap<T, Node<T>>();	}
	
	public void addNode(T key) {
		if(!nodeList.containsKey(key)) {
			Node<T> newNode = new Node<T>(key); 
			nodeList.put(key, newNode);
		}
		
	}
	
	public Node<T> get(T key){
		return nodeList.get(key);
	}
	
	public boolean contains(T key) {
		return nodeList.containsKey(key);
	}
	
	public Iterator<Entry<T, Node<T>>> getIterator() {
		return nodeList.entrySet().iterator();
				
	}
	
	public void updateNodeNeighbors(T key, T synKey) {
		
		if(nodeList.get(key) != null) {
			nodeList.get(key).addNeighbor(synKey);
		}
		if(nodeList.get(synKey) != null) {
			nodeList.get(synKey).addNeighbor(key);
		}
	}
	
	public void printNodeList() {
		Iterator<Entry<T, Node<T>>> iterator = nodeList.entrySet().iterator();
		
		while(iterator.hasNext()) {
			Entry<T, Node<T>> entry = iterator.next();
			
			System.out.print(entry.getKey() + " , ");
			entry.getValue().printNeighbor();
			
		}
	}
	
	
}
