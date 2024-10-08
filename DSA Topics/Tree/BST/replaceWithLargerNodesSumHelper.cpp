/**********************************************************
Problem statement
Given a binary search tree, you have to replace each node's data with the sum of all nodes which are greater or equal than it. You need to include the current node's data also.

That is, if in given BST there is a node with data 5, you need to replace it with sum of its data (i.e. 5) and all nodes whose data is greater than or equal to 5.

Note: You don't need to return or print, just change the data of each node.

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
Time Limit: 1 second
Sample Input 1 :
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
Sample Output 1 :
18 
36 10 
38 31 
25 
	Following is the Binary Tree Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public: 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this->data = data;
        	left = NULL;
        	right = NULL;
    	}
	};

***********************************************************/

void replaceWithLargerNodesSumHelper(BinaryTreeNode<int> *root, int &cumulativeSum) {
    if (root == NULL)
        return;

    // Traverse the right subtree first (larger values)
    replaceWithLargerNodesSumHelper(root->right, cumulativeSum);

    // Update the cumulative sum and the current node's value
    cumulativeSum += root->data;
    root->data = cumulativeSum;

    // Traverse the left subtree (smaller values)
    replaceWithLargerNodesSumHelper(root->left, cumulativeSum);
}

void replaceWithLargerNodesSum(BinaryTreeNode<int> *root) {
    int cumulativeSum = 0;
    replaceWithLargerNodesSumHelper(root, cumulativeSum);
}