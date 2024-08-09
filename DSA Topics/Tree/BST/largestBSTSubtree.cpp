/**********************************************************
Problem statement
Given a Binary tree, find the largest BST subtree. That is, you need to find the BST with maximum height in the given binary tree. You have to return the height of largest BST.

Note :
The binary tree will be consisting of only unique elements.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 ≤ Number of nodes ≤ 10^5
1 ≤ Data of a node ≤ 10^6
Time Limit: 1 second
Sample Input 1:
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1


Sample Output 1:
2
#include <climits>
#include <vector>


// Struct to hold information about a subtree
struct TreeInfo {
    int minValue;
    int maxValue;
    int size;
    bool isBST;


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
#include <algorithm>
#include <climits>
#include <vector>


// Struct to hold information about a subtree
struct TreeInfo {
    int minValue;
    int maxValue;
    int size;
    bool isBST;
    int height;
};

// Helper function to find largest BST subtree
TreeInfo findLargestBST(BinaryTreeNode<int>* root) {
    if (root == NULL) {
        return {INT_MAX, INT_MIN, 0, true, 0}; // minValue, maxValue, size, isBST, height
    }

    TreeInfo left = findLargestBST(root->left);
    TreeInfo right = findLargestBST(root->right);

    TreeInfo current;
    current.minValue = min(root->data, min(left.minValue, right.minValue));
    current.maxValue = max(root->data, max(left.maxValue, right.maxValue));

    if (left.isBST && right.isBST && root->data > left.maxValue && root->data < right.minValue) {
        current.isBST = true;
        current.size = left.size + right.size + 1;
        current.height = max(left.height, right.height) + 1;
    } else {
        current.isBST = false;
        current.size = max(left.size, right.size);
        current.height = max(left.height, right.height);
    }

    return current;
}

// Function to return the height of the largest BST subtree
int largestBSTSubtree(BinaryTreeNode<int>* root) {
    TreeInfo result = findLargestBST(root);
    return result.height;
}