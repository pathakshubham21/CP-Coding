/**********************************************************
	Following is the Binary Tree Node class structure
Problem statement
Given a binary tree, check if it is balanced. Return true if given binary tree is balanced, false otherwise.

Balanced Binary Tree:
A empty binary tree or binary tree with zero nodes is always balanced. For a non empty binary tree to be balanced, following conditions must be met:
1. The left and right subtrees must be balanced.
2. |hL - hR| <= 1, where hL is the height or depth of left subtree and hR is the height or depth of right subtree.    
Detailed explanation ( Input/output format, Notes, Images )
Constraints
Time Limit: 1 second
Sample Input 1 :
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output 1 :
false
Sample Input 2 :
1 2 3 -1 -1 -1 -1
Sample Output 2 :
true


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
int height(BinaryTreeNode<int> *root)
{
	if(root==NULL)
	return 1;

	int l = height(root->left);
	int r = height(root->right);

	if(l>r)
	{
		return (l-r<=1)?1:0;
	}
	else{
		return (r-l<=1)?1:0;
	}
}
bool isBalanced(BinaryTreeNode<int> *root) {
	// Write your code here
	if(root==NULL)
	return true;

	if((root->left!=NULL && root->right ==NULL)|| (root->left==NULL && root->right !=NULL) || height(root)==0)
	{
		return false;
	}
	bool ans =  isBalanced(root->left) && isBalanced(root->right);

	return ans;
}