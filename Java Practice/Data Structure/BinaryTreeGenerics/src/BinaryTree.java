


public class BinaryTree<T extends Comparable<T>> {
	private BinaryTreeNode<T> root;
	
	public BinaryTree() {
		root = null;
	}
	
	public BinaryTree(BinaryTreeNode<T> newNode ) {
		root = new BinaryTreeNode<T>(newNode);
	}
	
	public BinaryTreeNode<T>getRoot(){
		return root;
	}
	
	public void add(T data) {
		if(root == null) {
			root = new BinaryTreeNode<>(data);
		}
		else {
			add(root, data);
		}
	}
	
	public void add (BinaryTreeNode<T> node, T data) {
		int cmp = node.getData().compareTo(data);
		if(cmp > 0) {
			if(node.getLeft() == null) {
				node.setLeft(new BinaryTreeNode<>(data));
			}
			else {
				add(node.getLeft(), data);
			}
		}
		else if(cmp <= 0) {
			if(node.getRight() == null) {
				node.setRight(new BinaryTreeNode<>(data));
			}
			else {
				add(node.getRight(), data);
			}
		}
		
	}
	
	public void inOrderPrint() {
		inOrderPrint(root);
	}
	
	public void inOrderPrint(BinaryTreeNode<T> node) {
		if(node.getLeft() != null) {
			inOrderPrint(node.getLeft());
		}
		System.out.print(node.getData() + "  ");
		if(node.getRight() != null) {
			inOrderPrint(node.getRight());
		}
		
		
	}
	
}
