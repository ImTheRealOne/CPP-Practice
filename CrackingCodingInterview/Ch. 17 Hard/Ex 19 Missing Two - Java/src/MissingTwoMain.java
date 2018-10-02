import java.util.Arrays;
import java.util.Collections;
import java.util.Random;

/**
 * 
 * @author ImTheRealOne
 *
 *
 *Missing Two: You are given an array with all the numbers from 1 to N appearing exactly once,
except for one number that is missing. How can you find the missing number in 0 (N) time and
0(1) space? What if there were two numbers missing?
 *
 *
 */
public class MissingTwoMain {
	
	
	public static void main(String [] args) {
		
		int shuffledArray [] = createMissingIntArray();
		
		System.out.println(oneMissingNum(shuffledArray));
	}
	
	public static void printArray(int arr[] ) {
		for(int i= 0; i < arr.length; i++) {
			System.out.print(arr[i]+ " ,  "); 
		}
		System.out.println();
	}
	
	public static int [] createMissingIntArray() {
		Random random = new Random();
		int size = 10;
		int missingNum = random.nextInt(size-1)+1;
		System.out.println("missingNum : " + missingNum);
		int arr[] = new int[size-1];
		for(int i = 1; i < size;i++) {
			if(i >= missingNum) {
				arr[i-1]= i+1; 
			}
			else {				
				arr[i-1]= i; 
			}
		}
		printArray(arr);
		arr = shuffleArray(arr);
		
		printArray(arr);
		return arr;
	}
	
	public static int [] shuffleArray(int arr[]) {
		int index = 0, temp = 0;
		Random random =  new Random();
		for (int i = arr.length-1; i > 0; i--) {
			index = random.nextInt(i+1);
			temp = arr[index];
			arr[index] = arr[i];
			arr[i] = temp; 
		}
		return arr;
	}
	
	public static int oneMissingNum(int arr []) {
		int missingInt = 0;
		int arrSum = 0;
		int noMissingSum = 0;
		
		for(int i = 1; i <= arr.length; i++) {
			arrSum += arr[i-1];
			noMissingSum += i;
		}
		noMissingSum += arr.length+1;
		missingInt = noMissingSum - arrSum;
		
		System.out.println("Expected : " + noMissingSum + " ,  Actual : " + arrSum);
		System.out.println("Missing Int : " + missingInt);
		
		return missingInt;
	}
	
	
	
}
