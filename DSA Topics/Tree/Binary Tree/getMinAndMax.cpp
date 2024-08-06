/**********************************************************
Problem statement
For a given a Binary Tree of type integer, find and return the minimum and the maximum data values.

Return the output as an object of Pair class, which is already created.

Note:
All the node data will be unique and hence there will always exist a minimum and maximum node data.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
2 <= N <= 10^5
Where N is the total number of nodes in the binary tree.

Time Limit: 1 sec
Sample Input 1:
8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
Sample Output 1:
1 14
Sample Input 2:
10 20 60 -1 -1 3 50 -1 -1 -1 -1 
Sample Output 2:
3 60


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

/*
	The first value of the pair must be the minimum value in the tree and 
	the second value of the pair must be the maximum value in the tree
*/

#include<climits>
void getMinAndMaxHelper(BinaryTreeNode<int>*root, pair<int,int>&ans)
{
	if(root==NULL)
	return;
	if(root->data<ans.first)
	{
		ans.first = root->data;
	}
	if(root->data>ans.second)
	{
		ans.second = root->data;
	}
	getMinAndMaxHelper(root->left,ans);
	getMinAndMaxHelper(root->right,ans);
}
pair<int, int> getMinAndMax(BinaryTreeNode<int> *root) {
	// Write your code here
	pair<int,int>ans;
	ans.first = INT_MAX;
	ans.second = INT_MIN;

	getMinAndMaxHelper(root,ans);
	return ans;

}