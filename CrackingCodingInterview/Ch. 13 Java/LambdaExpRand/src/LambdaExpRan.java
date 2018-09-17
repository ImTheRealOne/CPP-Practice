import java.util.ArrayList;
import java.util.Arrays;
import java.util.Random;

public class LambdaExpRan {


		public interface MyRandomSubsetArrayList{
			public ArrayList<Integer> randomSubset(ArrayList<Integer> set);
			
			
		
		}
		static void printList(ArrayList<Integer> set){
			System.out.println("Array Size : " + set.size());
			for(int i = 0; i < set.size(); i++){
				System.out.print(set.get(i)+ " ");
			}
		
		}
		public static void main(String[] args){
			
			ArrayList<Integer> set = new ArrayList<Integer>(Arrays.asList(1,2,3,4,5));
			
			MyRandomSubsetArrayList randomSubsetArrayList = (ArrayList<Integer> result) ->{
					Random random = new Random();
					ArrayList<Integer> resultList = new ArrayList<Integer>();
					int newSize = random.nextInt(set.size()-1);
					
					
					for(int i = 0; i < newSize; i++){
						int randomIndex = random.nextInt(newSize) + i;
						resultList.add(set.get(randomIndex));
						int temp = set.get(i);
						set.set(i, set.get(randomIndex));
						set.set(randomIndex, temp);
					
					}
					
					return resultList;
				
				};
			
			
				
			ArrayList<Integer> result = randomSubsetArrayList.randomSubset(set);
			
			printList(result);
			
			
			
		};

		
		
		
		
	

}
