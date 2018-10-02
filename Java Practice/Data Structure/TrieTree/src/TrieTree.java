
public class TrieTree {

	private TrieTreeNode root [];
	
	public TrieTree() {
		// TODO Auto-generated constructor stub
		root = new TrieTreeNode [26];
	}
	
	public void print(TrieTreeNode node) {
		
		System.out.print(node.getChar() + "   ");
		if(node.isWord()) {
			System.out.print("  word o_0 ");
		}
		for(int i = 0; i < node.getNodeArray().length; i++) {
			if(node.getNodeArray()[i]!= null) {
				print(node.getNodeArray()[i]);
			}
		}
		System.out.println();
	}
	
	public void print() {
		
		for(int i = 0; i < root.length; i++) {
			if(root[i]!= null ) {
				print(root[i]);
			}
		}
	}
	
	public void addWord(String word) {
		String lowerString = word.toLowerCase();
		int charIndex = lowerString.charAt(0) - 'a';
		if(root[charIndex] == null) {
			root[charIndex] = new TrieTreeNode(lowerString.charAt(0));
		}
		TrieTreeNode walker = root[charIndex];
		for(int i = 1; i< lowerString.length();i++) {
			charIndex = lowerString.charAt(i) - 'a';
			if(!walker.contains(charIndex)) {
				walker.getNodeArray()[charIndex] = new TrieTreeNode(lowerString.charAt(i));
				
			}
			walker = walker.getNextChar(charIndex);
			
		}
		walker.setWord();
		
	}
	
	public boolean contains(String word) {
		boolean result = true;
		
		if(word.isEmpty()) {
			return false;
		}
		int charIndex = word.charAt(0) - 'a';
		TrieTreeNode walker = null;
		if(root[charIndex] == null ) {	
			return false;
		}
		else {
			walker = root[charIndex];
			for(int i = 1; i < word.length() ; i++) {
				charIndex = word.charAt(i)-'a';
				
				if(!walker.contains(charIndex)) {
					return false;
				}
				walker = walker.getNextChar(charIndex);
				if(i+1 == word.length()) {
					return true;
				}
			}
		}

		return result;
	}
	
	public boolean validWord(String word) {
		boolean result = false;
		if(word.isEmpty()) {
			return result;
		}
		int charIndex = word.charAt(0) - 'a';
		TrieTreeNode walker = null;
		if(root[charIndex] != null ) {			
			walker = root[charIndex];
			for(int i = 1; i < word.length() ; i++) {
				charIndex = word.charAt(i)-'a';
				
				if(!walker.contains(charIndex)) {
					return result;
				}
				walker = walker.getNextChar(charIndex);
				if(i+1 == word.length()) {
					return walker.isWord();
				}
			}
		}

		return result;
	}
	
	
	
	

	
}
