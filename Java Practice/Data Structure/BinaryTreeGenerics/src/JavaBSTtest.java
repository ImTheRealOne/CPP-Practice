/**
 * 
 */

/**
 * @author ImTheRealOne
 *
 */
public class JavaBSTtest {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		BinaryTree<Integer> bsTree = new BinaryTree<>();
		
		bsTree.add(9);
		bsTree.add(11);
		bsTree.add(5);
		bsTree.add(3);
		bsTree.add(7);
		
		bsTree.inOrderPrint();
		
		System.exit(0);
	}

}
