/**********************************************************
	Problem statement
Given a binary tree, remove all leaf nodes from it. Leaf nodes are those nodes, which don't have any children.

Note:

1. Root will also be a leaf node if it doesn't have left and right child. 
2. You don't need to print the tree, just remove all leaf nodes and return the updated root.
Detailed explanation ( Input/output format, Notes, Images )
Constraints
Time Limit: 1 second
Sample Input 1:
8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
Sample Output 1:
8
3 10
6 14 
	
	Following is the Binary Tree Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public : 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this -> data = data;
        	left = NULL;
        	right = NULL;
    	}
	};

***********************************************************/

void removeLeafNodesHelper(BinaryTreeNode<int> *root)
{
		if(root==NULL)
		return;
		if(root->left!=NULL)
		{
			if(root->left->left==NULL && root->left->right==NULL)
			{
				root->left = NULL;

			}
		}
			if(root->right!=NULL)
		{
			if(root->right->left==NULL && root->right->right==NULL)
			{
				root->right = NULL;
			}
		}
	removeLeafNodesHelper(root->left);
	removeLeafNodesHelper(root->right);

}

BinaryTreeNode<int>* removeLeafNodes(BinaryTreeNode<int> *root) {

	if(root==NULL||(root->left==NULL && root->right==NULL))
	{
		return NULL;
	}

	removeLeafNodesHelper(root);
	return root;

    // Write your code here
}