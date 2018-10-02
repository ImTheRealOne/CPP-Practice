import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;


/**
 * 
 */

/**
 * @author ImTheRealOne
 *
 */
public class ReSpace {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		TrieTree trieTree = new TrieTree();
		trieTree.addWord("looked");
		trieTree.addWord("just");
		trieTree.addWord("like");
		trieTree.addWord("her");
		trieTree.addWord("brother");
		trieTree.addWord("at");
		trieTree.addWord("attack");
		trieTree.addWord("attacked");
		trieTree.addWord("look");
		trieTree.addWord("eddie");
		trieTree.print();
		
		
		ArrayList<String>words = new ArrayList<>(
				Arrays.asList("looked", "just", "like", "her", "brother"
													)); 
		
		System.out.println(trieTree.validWord("looked"));
		
		final String input = "herattacked";
		//final String input = "jesslookeddiejustliketimherbrother";
		
		HashMap<String, Boolean> dictionary = addToDictionary(words);
		//System.out.println(respaceUsingHashMapSlidingWindow(dictionary, input));
		//System.out.println(hashMapBruteRecursiveHelper(dictionary, input));
		
		System.out.println(respaceTrieTreeSlidingWindow(trieTree, input));
		
		System.exit(0);
	}
	
	public static HashMap<String, Boolean> addToDictionary(ArrayList<String> words){
		HashMap<String, Boolean> dictionary = new HashMap<>();
		
		for(String wordsIt : words) {
			String wordFragment = "";
			boolean validWord = false;
			for(int i = 0; i < wordsIt.length(); i++) {
				wordFragment += Character.toString(wordsIt.charAt(i));
				if(i+1 == wordsIt.length()) {
					validWord = true;
				}
				dictionary.put(wordFragment, validWord);
				validWord = false;
			}
		}
		System.out.println(dictionary.toString());;
		
		return dictionary;
	}
	
	public static String hashMapBruteRecursiveHelper(HashMap<String, Boolean > dictionary, String unspacedString) {
		String spacedString = "";
		
		spacedString = respaceUsingHasMapBruteRecursive(dictionary, unspacedString, spacedString, 0);
		
		return spacedString;
	}
	
	
	public static String respaceUsingHasMapBruteRecursive(HashMap<String, Boolean> dictionary, 
			String unspacedString, String spacedString, int currIndex) {
		if(currIndex >= unspacedString.length()) {
			return spacedString;
		}
		if(currIndex < unspacedString.length()) {
			spacedString += unspacedString.charAt(currIndex);
		}
		int walkerIndex = spacedString.length()-1;
		
		while(walkerIndex > 0 && spacedString.charAt(walkerIndex) != ' '){
			String wordFragment = spacedString.substring(walkerIndex, spacedString.length());
			
			if(dictionary.containsKey(wordFragment) && dictionary.get(wordFragment)) {
				int insertIndex = spacedString.length() - wordFragment.length();
				spacedString = new StringBuilder(spacedString).insert(spacedString.length() - wordFragment.length(), " ").toString();
				walkerIndex++;
			}
			walkerIndex--;
		}
		
		spacedString = respaceUsingHasMapBruteRecursive(dictionary, unspacedString, spacedString, currIndex+1);
		
		return spacedString;
	}
	
	public static String respaceUsingHashMapSlidingWindow(HashMap<String, Boolean> dictionary, String unspacedString) {
		String spacedString = "";
		
		if(unspacedString.isEmpty()) {
			return "error: empty string";
		}
		int leftWindow = 0;
		int rightWindow = 0;
		int unknownChars = 0;
		int validWordIndex = 0;
		String partialString = "";
		
		while(rightWindow < unspacedString.length()) {
			if(rightWindow < unspacedString.length()) {
				partialString += unspacedString.charAt(rightWindow);				
			}
			if(dictionary.containsKey(partialString)) {
				if(dictionary.get(partialString) == true ) {
					validWordIndex = rightWindow;
					if(rightWindow + 1 < unspacedString.length()) {						
						String partialPlusNextChar = partialString + unspacedString.charAt(rightWindow+1);
						if(dictionary.containsKey(partialPlusNextChar)) {
							 validWordIndex = rightWindow -1;	//how to handle at and attack?
						}
						else {
							spacedString = new StringBuilder(spacedString).insert(
													spacedString.length(), " ").toString();
							spacedString += partialString + " ";
							partialString = "";
							leftWindow = rightWindow;
							validWordIndex = 0;
						}
					}
				}
				if(partialString != "" && dictionary.get(partialString)) {
					spacedString += partialString;
				}
				
				rightWindow++;
				
			}
			else {
				
				while(!dictionary.containsKey(partialString)) {
					spacedString += partialString;
					partialString = "";
					leftWindow = rightWindow;
					rightWindow++;
					if(rightWindow < unspacedString.length()) {
						partialString += unspacedString.charAt(rightWindow);
					}
				}
				int countUnknownIndex = spacedString.length()-1;
				while(countUnknownIndex >= 0 && spacedString.charAt(countUnknownIndex) != ' ') {
					unknownChars++;
					countUnknownIndex--;
				}
				partialString = "";
				
				
				
			}
			
		}
		
		return spacedString;
	}
	
	public static String respaceTrieTreeSlidingWindow(TrieTree trieTree, String unspacedString) {
		String spacedString = "";
		
		String wordFragment = "";
		
		int leftWindow = 0;
		int rightWindow = 0;
		int unknownChars = 0;
		int lastValidWordIndex =0;
		String lastValidWord = "";
		for(int i = 0; i < unspacedString.length();i++) {
			wordFragment += unspacedString.charAt(i);
			//wordFragment is promising
			if(trieTree.contains(wordFragment)) {
				//wordFragment is a valid word
				if(trieTree.validWord(wordFragment)){
					lastValidWordIndex = i;
					lastValidWord = wordFragment;
					
					if(i+1 < unspacedString.length() && !trieTree.contains(
							wordFragment + unspacedString.charAt(i+1))) {
						if(spacedString.length() > 0 && 
					
							spacedString.charAt(spacedString.length()-1) != ' ') {
						spacedString += " ";
					}
					spacedString += wordFragment + " ";
					lastValidWordIndex = 0;
					wordFragment = "";
					lastValidWord = "";
					
					
					}
					
				}
			}
			else {
				//there was no last valid word current wordFragment is not promising
				if(lastValidWordIndex == 0) {
					
					spacedString += wordFragment;
					unknownChars += wordFragment.length();
					wordFragment = "";
				}
				else {
					//a valid word was found before check following characters to see if it had a longer valid word
					spacedString += " ";
					spacedString += lastValidWord;
					i = lastValidWordIndex + lastValidWord.length() -1;
					
					
					lastValidWord = "";
					lastValidWordIndex = 0;
				}
			}
			
		}
		
		if(!wordFragment.isEmpty()) {
			spacedString += wordFragment;
			unknownChars += wordFragment.length();
		}
		
		
		return spacedString;
	}

	
	
}
