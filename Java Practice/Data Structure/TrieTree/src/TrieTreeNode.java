
public class TrieTreeNode {
	private char character;
	boolean word;
	private TrieTreeNode [] nextNode ;
	
	
	public TrieTreeNode(char newChar) {
		character = newChar ;
		nextNode = new TrieTreeNode [26];
		word = false;
	}
	
	public TrieTreeNode [] getNodeArray() {
		return nextNode;
	}
	
	public char getChar() {
		return character;
	}
	
	public boolean contains(int charIndex) {
		if(nextNode[charIndex] == null) {
			return false;
		}
		return true;
	}
	
	public TrieTreeNode getNextChar(int charIndex) {
		if(nextNode[charIndex] == null) {
			return null;
		}
		
		return nextNode[charIndex];
	}
	
	public void setWord() {
		word = true;
	}
	
	public boolean isWord() {
		return word;
	}
}
