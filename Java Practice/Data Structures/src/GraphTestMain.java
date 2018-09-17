
public class GraphTestMain {

	public static void main(String args []) {
		
		Graph<String> graph = new Graph<String>();
		
		graph.addNode("John");
		graph.addNode("Jon");
		graph.addNode("Chris");
		graph.addNode("Kris");
		graph.addNode("Christopher");
		
		graph.updateNodeNeighbors("Jon", "John");
		graph.updateNodeNeighbors("John", "Johhny");
		
		graph.updateNodeNeighbors("Kris", "Chris");
		graph.updateNodeNeighbors("Kris", "Christopher");
		
		graph.printNodeList();
		
		System.exit(0);
	}
	
}
