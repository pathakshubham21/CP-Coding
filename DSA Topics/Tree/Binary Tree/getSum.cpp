/**********************************************************
	For a given Binary Tree of integers, find and return the sum of all the nodes data.

Example:
ALTIMAGE

When we sum up all the nodes data together, we get 150. Hence, the output will be 150.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= N <= 10^6
Where N is the total number of nodes in the binary tree.

Time Limit: 1 sec
Sample Input 1:
2 3 4 6 -1 -1 -1 -1 -1
Sample Output 1:
 15
Explanation :
The binary tree formed using the input values: 2, 3, 4, 6, -1, -1, -1, -1, -1. Hence the sum is 15. 
ALTIMAGE

Sample Input 2:
1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
Sample Output 2:
 28
	
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

int getSum(BinaryTreeNode<int>* root) {
	if(root==NULL)
	return 0;

	int ans = 0;
	ans = root->data+getSum(root->left)+getSum(root->right);
	return ans;
	


	
    // Write your code here
}