/**
 * 
 */

/**
 * @author ImTheRealOne
 * 
 * Letters and Numbers: Given an array filled with letters and numbers, find the longest subarray with
an equal number of letters and numbers.
 *
 */

import javafx.util.Pair;

public class LettersAndNumber {
	

	public static void main(String args[]) {
		
		
		char arr[] = {'1','1','1','1','1','1','1','1','q','q','1','q','q','1','q'};
		//arr = new char [] {'1','2','3','a','b','4','c','5'};
		
	
//		System.out.println(isNumber('a') ? "number": "not number");
//		System.out.println(isNumber('A') ? "number": "not number");
//		System.out.println(isNumber('/') ? "number": "not number");
//		System.out.println(isNumber('3') ? "number": "not number");
//		
//		System.out.println(isLetter('1') ? "letter": "not letter");
//		System.out.println(isLetter('/') ? "letter": "not letter");
//		System.out.println(isLetter('A') ? "letter": "not letter");
//		System.out.println(isLetter('a') ? "letter": "not letter");
//	
		Pair<Integer, Integer> result = longestEqualSubArray(arr);
		
		System.out.println("min Index : " + result.getKey() + "  max Index : " + result.getValue());
		
		for(int i = result.getKey(); i <= result.getValue(); i++) {
			System.out.print(arr[i]+ " " );
		}
		result = getNumberOfNumAndLetter(arr);
		System.out.println("total Num : " + result.getKey() + " total letters : " + result.getValue());
		
		System.out.println("press any key");
		try{System.in.read();}
		catch(Exception e){}
		
		System.exit(0);;
	}
	
	public static boolean isNumber(char input) {
		return (input >= '0' && input <= '9');
	}
	public static boolean isLetter(char input) {
		return ((input >= 'a' && input <= 'z') || (input >= 'A' && input <= 'Z' ));
	}
	//find largest sub array with equal number of letters and numbers
	public static Pair<Integer, Integer> longestEqualSubArray(char arr[]){
		Pair<Integer, Integer> minMaxIndex = new Pair<Integer, Integer>(0, 0);
		
		Pair<Integer, Integer> countOfNumAndLetter = getNumberOfNumAndLetter(arr);
		
		int totalNumOfIntegers = countOfNumAndLetter.getKey();
		int totalNumOfLetter = countOfNumAndLetter.getValue();
		//sliding window
		int leftWindowIndex = 0;
		int rightWindowIndex = 0;
		//running sum for letters and numbers
		int numberOfLetters = 0;
		int numberOfNumbers = 0;
		
		for(int i = 0; i < arr.length; i++) {
			rightWindowIndex = i;
			//count running sum
			if(isNumber(arr[i])) {
				numberOfNumbers++;
			}
			else if (isLetter(arr[i])) {
				numberOfLetters++;
			}
			//if curr sum of letters or numbers is larger than the max possible
			//slide left window index by 1 and decrement the current index
			if (numberOfLetters > totalNumOfIntegers ||
					numberOfNumbers > totalNumOfLetter
					) {
				System.out.println("asdfasdf" + i);
				if(isLetter(arr[leftWindowIndex])) {
					totalNumOfLetter--;
					numberOfLetters--;
				}
				else if (isNumber(arr[leftWindowIndex])) {
					totalNumOfIntegers--;
					numberOfNumbers--;
				}
				leftWindowIndex++;
				
			}
			//if equal number and letters check if its larger than any previous ones before updating
			if(numberOfLetters == numberOfNumbers) {
				if((rightWindowIndex-leftWindowIndex) > (minMaxIndex.getValue() - minMaxIndex.getKey())){	
					minMaxIndex = new Pair<Integer, Integer>(leftWindowIndex, rightWindowIndex);
					System.out.println("updated " + minMaxIndex.getKey() + " , " + minMaxIndex.getValue() );
				}
			}
			
			
			
		}
		
		
		return minMaxIndex;
	}
	
	//return total number of number and letters as a pair respectively
	public static Pair<Integer, Integer> getNumberOfNumAndLetter(char arr[]){
		Pair<Integer, Integer> numberofNumandLetter = new Pair<Integer, Integer>(0,0);
		int numberOfLetters = 0;
		int numberOfNumbers = 0;
		for(int i = 0; i < arr.length;i++) {
			if(isNumber(arr[i])) {
				numberOfNumbers++;
			}
			else if (isLetter(arr[i])) {
				numberOfLetters++;
			}
			
		}
		
		numberofNumandLetter = new Pair<Integer, Integer>(numberOfNumbers, numberOfLetters);
		
		return numberofNumandLetter;
	}
}
