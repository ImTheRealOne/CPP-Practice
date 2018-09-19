/**
 * 
 */

/**
 * @author ImTheRealOne
 *
 *
 *Circus Tower: A circus is designing a tower routine consisting of people standing atop one another's
shoulders. For practical and aesthetic reasons, each person must be both shorter and lighter
than the person below him or her. Given the heights and weights of each person in the circus, write
a method to compute the largest possible number of people in such a tower.
EXAMPLE
Input (ht, wt): (65 , 100) (70 , 150) (56 , 90) (75 , 190) (60 , 95) (68 , 110)
Output: The longest tower is length 6 and includes from top to bottom:
(56 , 90) (60 , 95) (65 , 100) (68 , l10) (70 , 150) (75 , 190)
 *
 *
 */

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;import javafx.scene.control.Tab;
import javafx.stage.Popup;
import javafx.util.Pair;

public class CircusTower {
	//global variables
	public static int totalCalls = 0;
	public static int maxPeople = 0;
	public static ArrayList<Pair<Integer, Integer>> maxList = new ArrayList<>();

	public static void main(String [] args) {
		
		ArrayList<Pair<Integer, Integer>> peopleHeightWeight = new ArrayList<>();
		peopleHeightWeight.add(new Pair<Integer, Integer>(65, 100));
		peopleHeightWeight.add(new Pair<Integer, Integer>(70, 150));
		peopleHeightWeight.add(new Pair<Integer, Integer>(56, 90));
		peopleHeightWeight.add(new Pair<Integer, Integer>(75, 190));
		peopleHeightWeight.add(new Pair<Integer, Integer>(60, 95));
		peopleHeightWeight.add(new Pair<Integer, Integer>(68, 110));
		
		printArrayList(sortListHeight(peopleHeightWeight));
		for(int i = 0; i < peopleHeightWeight.size();i++) {
			//presort the list to better optimize runtime
			bruteForceRecursive(sortListHeight(peopleHeightWeight), new ArrayList<Pair<Integer, Integer>>(), i);;
		}
		System.out.println("total calls : " + totalCalls);
		printArrayList(maxList);
		
		System.out.println("");
		System.exit(0);
	}
	
	public static void printArrayList(ArrayList<Pair<Integer, Integer>> list) {
		for(Pair<Integer, Integer> entry : list) {
			System.out.print(entry.getKey() + " , " + entry.getValue() + "    ");
		}
		System.out.println("");
	
	}
	//recursive solution iterating all possible combinations
	public static void bruteForceRecursive(ArrayList<Pair<Integer, Integer>> list,
			ArrayList<Pair<Integer, Integer>> result, int currIndex){
		totalCalls++;
		//printArrayList(result);
		
		SortByHeight compareHeight = new SortByHeight();
		SortByWeight compareWeight = new SortByWeight();
		//if result list is empty add first element into it
		if(result.isEmpty()) {
			result.add(list.get(currIndex));
		}
		//if result is larger than the max list copy it
		if(result.size() > maxList.size()) {
			maxList = (ArrayList<Pair<Integer, Integer>>) result.clone();
		}
		//iterate through the rest of the list array 
		for(int i = currIndex+1; i < list.size();i++) {
			//check if it's possible to add the next element to result list
			if(compareHeight.compare(result.get(result.size()-1), list.get(i)) < 0 
					&& compareWeight.compare(result.get(result.size()-1), list.get(i)) < 0) {
				
				result.add(list.get(i));
				//check we are on last element
				if(i+1 < list.size()) {
					bruteForceRecursive(list, result, i);
				}
				//remove last added element
				result.remove(result.size()-1);
				
			}
		}
		
	}
	

	

	//sort the Array by height calling the comparator class
	public static ArrayList<Pair<Integer, Integer>> sortListHeight(ArrayList<Pair<Integer, Integer>> list){
		
		Collections.sort(list, new SortByHeight());
		
		return list;
		
	}
	
}
//comparator class to compare two pair instances by height
class SortByHeight implements Comparator<Pair<Integer, Integer> >{

	@Override
	public int compare(Pair<Integer, Integer> personA, Pair<Integer, Integer> personB) {
		// TODO Auto-generated method stub
		return personA.getKey() - personB.getKey();
	}
	
}
//comparator class to compare two pair instances by weight
class SortByWeight implements Comparator<Pair<Integer, Integer>>{
	
	@Override
	public int compare(Pair<Integer, Integer> personA, Pair<Integer, Integer> personB) {
		// TODO Auto-generated method stub
		return personA.getValue() - personB.getValue();
	}
	
}