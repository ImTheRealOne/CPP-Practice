/**
 * 
 */

/**
 * @author ImTheRealOne
 * BiNode: Consider a simple data structure called BiNode, which has pointers to two other nodes.
public class BiNode {
}
public BiNode nodel, node2;
public int data;
The data structure BiNode could be used to represent both a binary tree (where nodel is the left
node and node2 is the right node) or a doubly linked list (where nodel is the previous node and
node2 is the next node). Implement a method to convert a binary search tree (implemented with
BiNode) into a doubly linked list. The values should be kept in order and the operation should be
performed in place (that is, on the original data structure).
 *
 */
public class BiNode {

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
		bsTree.add(6);
		bsTree.add(8);
		bsTree.add(10);
		bsTree.add(15);
		bsTree.add(14);
		
		bsTree.inOrderPrint();
		System.out.println();
		convertBSTtoDoublyLinkList(bsTree);
		System.out.println(bsTree.getRoot().getData());
		System.out.println("most left : "  + ((bsTree.getRoot()).getMostLeft()).getData());
		printDoublyLinkedList((bsTree.getRoot()).getMostLeft());

		System.exit(0);
	}
	
	public static BinaryTreeNode<Integer> convertBSTtoDoublyLinkList(BinaryTree<Integer> bsTree){
		BinaryTreeNode<Integer> result = null;
		
		inOrderTraversal( bsTree.getRoot());
		
		return bsTree.getRoot().getMostLeft();
	}
	
	public static void inOrderTraversal(BinaryTreeNode<Integer> node) {
		if(node.getLeft() == null && node.getRight() == null) {
			return;
		}
		if(node.getLeft() != null) {
			inOrderTraversal(node.getLeft());
		}
		
		
		if(node.getRight() != null) {
			inOrderTraversal(node.getRight());
		}
		if(node.getLeft() != null) {
			node.setLeft(convertLeft(node.getLeft()));
			node.getLeft().setRight(node);
		}
		if(node.getRight() != null) {
			node.setRight(convertRight(node.getRight()));
			node.getRight().setLeft(node);
		}
	}
	
	public static BinaryTreeNode<Integer> convertLeft(BinaryTreeNode<Integer> node) {
		
		if(node.getLeft() == null && node.getRight() == null) {
			return node;
		}
		
		if(node.getLeft() != null) {
			node.getLeft().setRight(node);
		}
		if(node.getRight() != null) {
			node.getRight().setLeft(node);
			BinaryTreeNode<Integer> walker = node.getRight();
			while(walker.getRight() != null) {
				walker = walker.getRight();
			}
			return walker;
		}
		
		return node;
		
		
		
	}
	
	public static BinaryTreeNode<Integer> convertRight(BinaryTreeNode<Integer> node) {
		if(node.getLeft() == null && node.getRight() == null) {
			return node;
		}
		if(node.getRight() != null) {
			node.getRight().setLeft(node);
		}
		if(node.getLeft() != null) {
			node.getLeft().setRight(node);
			BinaryTreeNode<Integer> walker = node.getLeft();
			while(walker.getLeft() != null) {
				walker = walker.getLeft();
			}
			return walker;
		}
		
		return node;
	}

	public static void printDoublyLinkedList(BinaryTreeNode<Integer> node) {
		if(node != null) {
			System.out.print("Node : " + node.getData());
		}
		if(node.getLeft() != null) {
			System.out.print("  left : " + node.getLeft().getData());
		}
		if(node.getRight() != null) {
			System.out.print(" right : " + node.getRight().getData());
		}
		
		System.out.println();
		if(node.getRight() != null) {
			printDoublyLinkedList(node.getRight());
		}
	}
	
}
