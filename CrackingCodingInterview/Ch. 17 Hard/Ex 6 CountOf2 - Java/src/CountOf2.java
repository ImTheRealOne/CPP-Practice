
public class CountOf2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		System.out.println("total : " + BruteForce(20));
		
		
		System.exit(0);
	}
	
	public static int BruteForce (int n) {
		int count = 0;
		for(int i =  0 ;i <= n ; i += 2) {
			if(Integer.toString(i).contains("2")) {
				System.out.println(i);
				count++;
			}	
		}
		return count;
	}
	
	public static int multiplicationMethod(int n) {
		int count = 0;
		String numberString = Integer.toString(n);
		int multiplier = 0;
		
		for(int i = numberString.length(); i > 0; i--) {
			if(numberString.charAt(i) > '2' ) {
				if(i == numberString.length()) {
					count +=1 ;
				}
				else {
					multiplier += 10;
				}
			}
			
			
		}
		
		
		return count;
	}

}
