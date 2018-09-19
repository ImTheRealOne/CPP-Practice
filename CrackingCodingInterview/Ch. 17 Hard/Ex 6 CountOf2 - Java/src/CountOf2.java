
public class CountOf2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		System.out.println("total : " + BruteForce(27));
		
		
		System.exit(0);
	}
	
	public static int BruteForce (int n) {
		int count = 0;
		for(int i =  0 ;i <= n ; i ++) {
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
				
			}
			
			
			
		}
		
		
		return count;
	}

}
