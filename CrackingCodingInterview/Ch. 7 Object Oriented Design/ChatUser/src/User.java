import java.awt.Dimension;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.DataInputStream;
import java.io.IOException;
import java.io.PrintStream;
import java.net.Socket;
import java.net.UnknownHostException;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JTextField;


public class User  implements Runnable{
	private String userName;
	private String userPassword;
	private Socket socket;
	private PrintStream outputStream;
	private DataInputStream inputStream;
	private JPanel jPanel;
	private JTextArea jTextArea;
	private JTextField messageField;
	private JScrollPane jScrollPane;
	private JButton sendButton;
	private JFrame jFrame;
	
	
	User(String newUserName, String newUserPassword){
		userName = newUserName;
		userPassword = newUserPassword;
		initializeFrame();
		
		connect();
	}
	public void initializeFrame(){
		jFrame = new JFrame("Chat Client : " + userName);
		jFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		jFrame.setSize(400, 500);
		jPanel = new JPanel();
		jTextArea = new JTextArea();
		jTextArea.setPreferredSize(new Dimension(300, 300));
		messageField = new JTextField();
		messageField.setPreferredSize(new Dimension(200, 50));
		jScrollPane = new JScrollPane(jTextArea);
		jPanel.add(jScrollPane);
		jPanel.add(messageField);
		initializeSendButton();
		jPanel.add(sendButton);
		jFrame.setContentPane(jPanel);
		jFrame.setVisible(true);
		
	}
	
	
	public void initializeSendButton(){
		sendButton = new JButton("send");
		sendButton.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				String msg = messageField.getText();
				if(!msg.isEmpty()){
					outputStream.println(userName + " : " + msg);
					messageField.setText("");
					//testScroll();
				}
				
				
			}
		});
	}
	public void testScroll(){
		for(int i = 0; i < 99; i ++){
			outputStream.println(i + "asdfa");
		}
	
	}
	
	public void connect() {
		try{
			socket = new Socket("localhost", 1234);
			outputStream = new PrintStream(socket.getOutputStream());
			inputStream = new DataInputStream(socket.getInputStream());
		} catch (UnknownHostException e){
			System.out.println(userName + "Cannot connect to local host");
			System.exit(1);
		} catch (IOException e) {
			System.out.println("IO error ");
		}
	
	}
	
	
	public void disconnect(){
		try{
			outputStream.close();
			inputStream.close();
			socket.close();
		}
		catch (IOException e){
			System.out.println(e);
		}
	
	}


	@Override
	public void run() {
		String line;
		while(true){
			try {
				line = inputStream.readLine();
				
				jTextArea.append(line + "\n");
			}catch(IOException e){
				System.out.println("read failed");
				System.exit(-1);
			}
		}
		
	}
}
