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


public class User extends JFrame implements Runnable{
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
	
	
	
	User(String newUserName, String newUserPassword){
		userName = newUserName;
		userPassword = newUserPassword;
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setSize(400, 500);
		setTitle("Chat Client : " + userName);
		jPanel = new JPanel();
		jTextArea = new JTextArea();
		messageField = new JTextField();
		messageField.setPreferredSize(new Dimension(200, 50));
		jScrollPane = new JScrollPane(jTextArea);
		jPanel.add(jScrollPane);
		jPanel.add(messageField);
		initializeSendButton();
		jPanel.add(sendButton);
		setContentPane(jPanel);
		setVisible(true);
		connect();
		run();
	}
	
	
	public void initializeSendButton(){
		sendButton = new JButton("send");
		sendButton.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				String msg = messageField.getText();
				outputStream.println(userName + " : " + msg);
				messageField.setText("");
				
			
			}
		});
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
				outputStream.println(line);
				jTextArea.append(line);
			}catch(IOException e){
				System.out.println("read failed");
				System.exit(-1);
			}
		}
		
	}
}
