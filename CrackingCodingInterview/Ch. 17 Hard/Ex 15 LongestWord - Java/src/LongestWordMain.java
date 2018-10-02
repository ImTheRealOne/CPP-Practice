import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashSet;
/**
 * 
 */

/**
 * @author ImTheRealOne
 * 
 * Longest Word: Given a list of words, write a program to find the longest word made of other words
in the list.
EXAMPLE
Input: cat, banana, dog, nana, walk, walker, dogwalker
Output: dogwalker
 *
 *
 *Solution : recusive solution
 *				1) add each word into a HashSet for O(1) look up
 *				2) build a string adding letter by letter of each word checking if the hashset contains the fragment
 *				3) get the largest word length
 *
 *				//Suggestion optimization : perhaps sort the list by length once you find the longest length you can ignore 
 *				//all words shorter than the longest length
 */		
public final class LongestWordMain {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		String listring [] = {"at","att","attack","tack", "cat", "banana", "dog", "nana",
								"walk", "walker"};
		
		HashSet<String> set = createSet(listring);
		
		System.out.println(longestCompositeWord(set, listring));
		
		System.exit(0);
	}
	//create a hashset of each word
	public static HashSet<String> createSet(String arr [] ){
		HashSet<String> set = new HashSet<>();
		
		for(int i = 0; i < arr.length; i++) {
			
			set.add(arr[i].toLowerCase())	;
		}
		
		return set;
	}
	
	//iterate through each word and checking if the word is a valid composite word
	//keep track of the longest one
	public static String longestCompositeWord (HashSet<String> set, String arr [] ) {
		String compositeWord = "";
		
		for(int i = 0; i < arr.length; i++) {
			if(isComposite(set, arr[i], 0)) {
				if(arr[i].length() > compositeWord.length()){
					compositeWord = arr[i];
				}
			}
			
		}
		
		return compositeWord;
	}
	
	//recursive function that check if the word is a composite word
	//compositelevel is used to check if the word was parsed into at least 2 word
	public static boolean isComposite(HashSet<String> set, String word, int compositeLevel) {
		String wordFragment = "";
		//initialize word is not a composite
		boolean result = false;
		//if the word was parsed into at least 2 words and all letters are used
		//then the word is a composite
		if(compositeLevel > 1 && word.isEmpty()) {
			return true;
		}
		
		for(int i = 0; i < word.length(); i++) {
			//add letter to the word fragment
			wordFragment += word.charAt(i);
			//once the word fragement is a word in the set 
			if(set.contains(wordFragment)) {
				//put the rest of the letters into subfragment and check if those letters is a composite word
				String subFragment = word.substring(
							wordFragment.length(), word.length());
				
					//recursely check the subfragment and add one to the composite level to indicate
					//the subfragment is indeed a composite
					result = isComposite(set, subFragment, compositeLevel+1);
					//if the composite does return true then add one to composite to indicate it is a composite
					if(result) {
						compositeLevel += 1;
					}
				
				
			}
		}
		//return the recurse result
		return result;
	}

}
