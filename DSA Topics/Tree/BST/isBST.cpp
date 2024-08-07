/**********************************************************
Given a binary tree with N number of nodes, check if that input tree is BST (Binary Search Tree). If yes, return true, return false otherwise.

Note:
Duplicate elements should be kept in the right subtree.
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
0 <= Number of edges <= 10^5
Time Limit: 1 second
Sample Input 1 :
3 1 5 -1 2 -1 -1 -1 -1


Sample Output 1 :
true
Sample Input 2 :
5 2 10 0 1 -1 15 -1 -1 -1 -1 -1 -1


Sample Output 2 :
false

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
#include<climits>
int getLow(BinaryTreeNode<int>* root) {
    if (root == NULL) {
        return INT_MAX;
    }
	int val = root->data;
	int l = getLow(root->left);
	int r= getLow(root->right);

    return min(val, min(l,r));
}

int getHigh(BinaryTreeNode<int>* root) {
    if (root == NULL) {
        return INT_MIN;
    }

 	int val = root->data;
	int l = getHigh(root->left);
	int r= getHigh(root->right);

    return max(val, max(l,r));
}

bool isBST(BinaryTreeNode<int>* root) {
    if (root == NULL) {
        return true;
    }

    int leftTreeHigh = getHigh(root->left);
    int rightTreeLow = getLow(root->right);

    if (root->data <= leftTreeHigh || root->data >= rightTreeLow) {
        return false;
    }

    return isBST(root->left) && isBST(root->right);
}
