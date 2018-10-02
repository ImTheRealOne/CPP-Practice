/**
 * 
 */

/**
 * @author ImTheRealOne
 *
 */
public class TrieTreeDriver {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		TrieTree trieTree = new TrieTree();
		
		trieTree.addWord("aaa");
		trieTree.addWord("aab");
		trieTree.addWord("bbb");
		
		trieTree.print();
		
		System.exit(0);
	}

}
