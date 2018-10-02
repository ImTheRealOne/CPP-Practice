
public class BinaryTreeNode<T extends Comparable<T>>  {
	
	private T data;
	private BinaryTreeNode<T> left;
	private BinaryTreeNode<T> right;
	
	public BinaryTreeNode(T newData) {
		data = newData;			
		left = null;
		right = null;
	}
	
	public BinaryTreeNode(BinaryTreeNode<T> copyNode) {
		this.data = copyNode.getData();
		this.left = new BinaryTreeNode<T>(copyNode.getLeft().getData());
		this.right = new BinaryTreeNode<T>(copyNode.getRight().getData());
		
	}
	
	public void setData(T newData) {
		data = newData;
	}
	
	public void setLeft (BinaryTreeNode<T> newLeft) {
		this.left =  newLeft;
	}
	
	public void setRight(BinaryTreeNode<T> newRight) {
		this.right = newRight;
	}
	
	public T getData() {
		return data;
	}
	
	public BinaryTreeNode<T> clone(){
		return  this;
	}
	
	public BinaryTreeNode<T> getRight(){
		return right;
	}
	
	public BinaryTreeNode<T> getLeft(){
		return left;
	}
	
	public BinaryTreeNode<T> getMostLeft(){
		if(this.getLeft() != null) {
			return getMostLeft(this.getLeft());
		}
		else {
			return null;
		}
	}
	
	public BinaryTreeNode<T> getMostLeft(BinaryTreeNode<T> node){
		if(node.getLeft() != null) {
			return getMostLeft(node.getLeft());
		}
		else {			
			return node;
		}
	}
	
	public BinaryTreeNode<T>getMostRight(){
		if(this.getRight() != null) {
			return getMostRight(this.getRight());
		}
		else {
			return null;
		}
	}
	
	public BinaryTreeNode<T> getMostRight(BinaryTreeNode<T> node){
		if(node.getRight() != null) {
			return getMostRight(node.getRight());
		}
		return node;
	}
}
