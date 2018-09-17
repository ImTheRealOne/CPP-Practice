import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.Map.Entry;



public class SynonymousName {
	
	private  HashMap<String, ArrayList<String>> nameToName;
	
	public SynonymousName() {
		nameToName = new HashMap<String, ArrayList<String>>();
	}
	
	public  void add(String name, String synName) {
		if(nameToName.containsKey(name)) {
			nameToName.get(name).add(synName);
		}
		else {
			nameToName.put(name, new ArrayList<String>() {{add(synName);}});
		}
	}
	
	Iterator<Map.Entry<String, ArrayList<String>>> getIterator(){
		Iterator<Map.Entry<String, ArrayList<String>>> iterator = nameToName.entrySet().iterator();

		return iterator;
	}
	public boolean contains(String key) {
		return (nameToName.containsKey(key));
	}
	
	public  ArrayList<String> get(String key){
		if(nameToName.containsKey(key)) {
			return nameToName.get(key);
		}
		return new ArrayList<String>();
	}
	
	public void print() {
		Iterator<Entry<String, ArrayList<String>>> it = nameToName.entrySet().iterator();
		
		while(it.hasNext()) {
			Entry<String, ArrayList<String>> pair = (Entry<String, ArrayList<String>>) it.next();
			
			System.out.print("name : " + pair.getKey() + " -> ");
			for(String names : pair.getValue()) {
				System.out.print(names + " , ");
			}
			System.out.println();
		}
	}
}
