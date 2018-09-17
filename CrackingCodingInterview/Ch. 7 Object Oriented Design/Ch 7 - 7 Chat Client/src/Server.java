import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ConnectException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
public class Server extends JFrame implements  Runnable{
	
	ServerSocket serverSocket;
	PrintWriter out;
	BufferedReader in;
	private JPanel jPanel;
	private JTextArea jTextArea;
	private JScrollPane jScrollPane;
	private ArrayList<User> userList; 
	Server(){
		initializeFrame();
		initializeServer();
		run();
	}
	
	public void initializeFrame(){
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setSize(400, 500);
		setTitle("Chat Server");
		jPanel = new JPanel();
		jTextArea = new JTextArea();
		jTextArea.append("Chat : 1234" + "\n");
		jScrollPane = new JScrollPane(jTextArea);
		jPanel.add(jScrollPane);
		setContentPane(jScrollPane); 
		setVisible(true);
	}
	
	public void initializeServer(){
		try{
			serverSocket = new ServerSocket(1234);
			Socket clientSocket = serverSocket.accept();
			out = new PrintWriter(clientSocket.getOutputStream(), true);
			in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
		}
		catch(ConnectException e){
			System.out.println("connectio error");
		}
		catch (IOException e){
			System.out.println("io error");
		}
	
	
	}
	
	@Override
	public void run() {
		String inputLine, outputLine;
		   while (true){
			  try {
				  inputLine = in.readLine();
				if(inputLine != null){ 
					jTextArea.append(inputLine + "\n");
					out.println(inputLine);
				  }
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			   
		   }
		      
		
	}
}
