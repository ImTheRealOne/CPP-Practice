package DataStructure;
import java.util.ArrayList;
/**
 * 
 * @author ImTheRealOne
 *
 */
public class BitVector {
	
	ArrayList<Integer> bitVector;
	
	public BitVector() {
		bitVector = new ArrayList<>();
	}
	
	public BitVector(int N) {
		bitVector = new ArrayList<>();
		for(int i = 0; i < N/32; i++) {
			bitVector.add(0);		
		}
	}
	
	public void setBit(int N) {
		
	}
	
	public void getBit(int N) {
		
	}
	
	
}
