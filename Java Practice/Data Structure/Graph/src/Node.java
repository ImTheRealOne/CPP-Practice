import java.util.ArrayList;

public class Node<T>{
	private T data;
	private ArrayList<T> neighbors;
	private boolean visited;
	public Node(T object) {
		data = object;
		visited = false;
		neighbors = new ArrayList<T>();
	}
			
	public Node() {
		data = null;
	}
	public T getData() {
		return data;
	}
	
	public boolean hasVisited() {
		return visited;
	}
	
	public void visitied() {
		visited = true;
	}
	
	public boolean addNeighbor(T newNeighbor) {
		
		for(T neighborIterator: neighbors ) {
			if(neighborIterator == newNeighbor) {
				return false;
			}
		}
		this.neighbors.add(newNeighbor);
		return true;
	}
	
	public ArrayList<T> getNeighbors(){ 
		return neighbors;
	}
	
	public void printNeighbor() {
		for(T neighborIterator : neighbors) {
			System.out.print( " -> " + neighborIterator);
		}
		
		System.out.println("");
	}
	
	
	
}
