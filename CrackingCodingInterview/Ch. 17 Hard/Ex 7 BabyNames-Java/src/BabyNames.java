/**
 * 
 */

/**
 * @author ImTheRealOne
 *
 *
 *Baby Names: Each year, the government releases a list of the 10000 most common baby names
and their frequencies (the number of babies with that name). The only problem with this is that
some names have multiple spellings. For example, "John" and "Jon" are essentially the same name
but would be listed separately in the list. Given two lists, one of names/frequencies and the other
of pairs of equivalent names, write an algorithm to print a new list of the true frequency of each
name. Note that if John and Jon are synonyms, and Jon and Johnny are synonyms, then John and
Johnny are synonyms. (It is both transitive and symmetric.) In the final list, any name can be used
as the "real " name.
 *
 *
 */
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Set;
import java.util.ArrayList;
import javafx.util.Pair;


public class BabyNames {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
	/*	
		//non graph implementation of the problem 
	HashMap<String, Integer> nameToPeople = new HashMap<>();
		nameToPeople.put("John"	, 15);
		nameToPeople.put("Jon", 12);
		nameToPeople.put("Chris", 13);
		nameToPeople.put("Kris", 4);
		nameToPeople.put("Christopher", 19);
		
		SynonymousName nameToNames = new SynonymousName();
		
		nameToNames.add("Jon", "John");
		nameToNames.add("John", "Johnny");
		nameToNames.add("Chris", "Kris");
		nameToNames.add("Chris", "Christopher");
		

		nameToNames.print();
		
		ArrayList<Pair<String, Integer>> result = countSynonymousPopulation(nameToPeople, nameToNames);
		
		for(Pair<String, Integer> it : result) {
			System.out.println(it.getKey() + " , " + it.getValue());
		}
		
		*/
		
		ArrayList<Pair<String, Integer>> namesToPeople = new ArrayList<Pair<String, Integer>>();
		
		namesToPeople.add( new Pair<String, Integer>("Jon" , 12));
		namesToPeople.add(new Pair<String, Integer>("John", 15));
		namesToPeople.add(new Pair<String, Integer>("Chris", 13));
		namesToPeople.add(new Pair<String, Integer>("Kris", 4));
		namesToPeople.add(new Pair<String, Integer>("Christopher", 19));
		
		
		ArrayList<Pair<String, String>> namesToNames = new ArrayList<>();
		
		namesToNames.add(new Pair<String, String>("Jon", "John"));
		namesToNames.add(new Pair<String, String>("John", "Johnny"));
		namesToNames.add(new Pair<String, String>("Chris", "Kris"));
		namesToNames.add(new Pair<String, String>("Chris", "Christopher"));
		
		
		
		
		Graph<String> graph = new Graph<String>();
		
		graph = createGraph(namesToNames);
		graph.printNodeList();
		
		ArrayList<Pair<String, Integer>> result = countSynPeople(graph, namesToPeople);
		for(Pair<String, Integer> arrayIterator : result) {
			System.out.println(arrayIterator.getKey() + " : " + arrayIterator.getValue());
		}
		
		System.exit(0);
	}
	
	public static int getPeople(String name, ArrayList<Pair<String, Integer>> namesToPeople) {
		int numberOfPpl = 0;
		
		for(Pair<String, Integer> arrayIterator : namesToPeople) {
			if(arrayIterator.getKey() == name) {
				return arrayIterator.getValue();
			}
		}
		
		return numberOfPpl;
	}
	
	public static ArrayList<Pair<String, Integer>> countSynPeople(Graph<String>graph, ArrayList<Pair<String, Integer>> namesToPeople ){
		ArrayList<Pair<String, Integer>> result = new ArrayList<>();
		
		Iterator<Entry<String, Node<String>>> graphIterator = graph.getIterator();
		
		ArrayList<Node<String>> queue = new ArrayList<>();
		//iterate through the hash map
		while(graphIterator.hasNext()) {
			Entry<String, Node<String>> entry = graphIterator.next();
			
			Node<String> visitNode = entry.getValue();
			int totalPeople = 0;
			//check if node has been visited
			if(!visitNode.hasVisited()) {
				visitNode.visitied();
				//add node to queue for bfs search
				queue.add(visitNode);
				while(!queue.isEmpty()) {
					//add all connected nodes to total people
					for(String neighbors : visitNode.getNeighbors()) {
						Node<String>neighborNode  = graph.get(neighbors);
						if(!neighborNode.hasVisited()) {
							neighborNode.visitied();
							queue.add(neighborNode);
						}
					}
					totalPeople += getPeople(visitNode.getData(), namesToPeople);
					if(queue.size() > 0) {
						queue.remove(0);
						if(!queue.isEmpty()) {
							visitNode = queue.get(0);
							
						}
					}
				}
				
			}
			
			if(totalPeople != 0) {
				result.add(new Pair<String, Integer> (visitNode.getData(), totalPeople));
			}
			graphIterator.remove();
		}
		
		
		return result;
	}
	//create map form names to name
	public static Graph<String> createGraph(ArrayList<Pair<String, String>> namesToNames) {
		Graph<String> graph = new Graph<>();
		
		for(Pair<String, String> arrayIterator: namesToNames) {
			graph.addNode(arrayIterator.getKey());
			graph.addNode(arrayIterator.getValue());
			
			graph.updateNodeNeighbors(arrayIterator.getKey(), arrayIterator.getValue());
			
		}
		
		return graph;
	}
	
	public static ArrayList<Pair<String, Integer>> countSynonymousPopulation(HashMap<String, Integer> nameToPeople,
			SynonymousName synonymousName){
		ArrayList<Pair<String, Integer>> result = new ArrayList<>();
	
		ArrayList<String> processNames = new ArrayList<String>();
		//iterate through the hash map looking for keys that hasn't been processed
		Iterator<Map.Entry<String, ArrayList<String>>> it = synonymousName.getIterator();
		while (it.hasNext()) { 
			Map.Entry<String, ArrayList<String>> entry = it.next();
			// even if you don't have a synName you should check how many ppl have that name
			if(!synonymousName.get(entry.getKey()).isEmpty()) {
				//get the associated name with the starting name
				ArrayList<String> entryList = entry.getValue();
				int totalpeople = 0;
				//check if the name has been process and if it's in the map
				if(synonymousName.contains(entry.getKey()) && !processNames.contains(entry.getKey())) {
					totalpeople += nameToPeople.get(entry.getKey());
					processNames.add(entry.getKey());
					for(String name : entry.getValue()) {
						//check if name from synonymous name has been processed
						if(!processNames.contains(name)) {
							processNames.add(name);
							if(nameToPeople.containsKey(name)) {							
								totalpeople += nameToPeople.get(name);
							}
						}
					}
				}
				if(totalpeople != 0) {					
					result.add(new Pair<String, Integer>(entry.getKey(), totalpeople));
				}
				
			}
			
		}
		
		return result;
	}

}
