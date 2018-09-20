import java.net.Inet4Address;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Map.Entry;

import javax.swing.text.StyledEditorKit.ForegroundAction;

import java.util.Set;

/**
 * 
 */

/**
 * @author ImTheRealOne
 * 
 * 
 * Kth Multiple: Design an algorithm to find the kth number such that the only prime factors are 3, 5,
and 7. Note that 3, 5, and 7 do not have to be factors, but it should not have any other prime factors.
For example, the first several multiples would be (in order) 1, 3, 5,7,9, 15,21.
 *
 */
public class KthMultiple {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println(Math.pow(5, 0));
		System.out.println("kth place : " + calculateMultiplesBruteForce(15));
		
		System.exit(0);
	}
	//a priority queue add for arrayList
	public static ArrayList<Integer> priorityAdd(ArrayList<Integer> list, int newNumber){
		ArrayList<Integer> result = list;
		boolean added = false;
		for(int i = 0; i < list.size() && !added;i++) {
			if(list.get(i) > newNumber) {
				list.add(i, newNumber);
				i++;
				added = true;
			}
			
		}
		if(!added) {
			list.add(newNumber);
		}
		
		return result;
	}
	//using the idea that 3*a1, 5*a1, 7*a1 and repeating it k times will give you
	//the kth multiple
	public static int  calculateMultiplesBruteForce(int k){
		
		
		ArrayList<Integer> list = new ArrayList<>(Arrays.asList(1,3,5,7));
		
		int currIndex = 1;
		int targetIndex = list.size();
		//priority adding the product will give you the kth multiple
		while(list.size()-1 < k || currIndex < k) {
			int threes = 3*list.get(currIndex);
			int fives = 5 * list.get(currIndex);
			int sevens = 7 * list.get(currIndex);
			
			if(!list.contains(threes)) {
				list = priorityAdd(list, threes);
			}
			if(!list.contains(fives)) {
				list = priorityAdd(list, fives);
			}
			if(!list.contains(sevens)) {
				list = priorityAdd(list, sevens);
			}
			System.out.println(list.toString());
			currIndex++;
		}
		
		for(int walker : list) {
			System.out.print(walker + "  ");
		}
		
		
		return list.get(k-1);
	}
		

}
