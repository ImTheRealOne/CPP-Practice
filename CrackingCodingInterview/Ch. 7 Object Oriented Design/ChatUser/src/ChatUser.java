
public class ChatUser {
	public static void main(String args[]){
		User userMin;
		User userDavid;
		
		Thread minThread = new Thread(userMin = new User("min",  "asdf"));
		
		Thread davidThread = new Thread(userDavid = new User("david",  "asdf"));
		minThread.start();
		davidThread.start();
		
		while(true){
			
			
		}
	}
}
