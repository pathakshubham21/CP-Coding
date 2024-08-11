
// Problem statement
// Given a BST and an integer K, you need to find the Kth smallest element present in the BST. Return INT_MIN if that is not present in the BST.

// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input :
// 8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
// 3
// Sample Output :
// 6

#include<vector>

void findNodeHelper(BinaryTreeNode<int>*root,vector<int>&result)
{
	if(root==NULL)
	return;

	findNodeHelper(root->left,result);
	result.push_back(root->data);
	findNodeHelper(root->right,result);
	
}

int findNode(BinaryTreeNode<int>* root, int k) {
		// Write your code here
		if(root==NULL)
		return -1;

		vector<int>result;

		 findNodeHelper(root,result);
		 return result[k-1];


}