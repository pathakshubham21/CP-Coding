/**********************************************************
Problem statement
Given a BST and an integer k. Find and return the path from the node with data k and root (if a node with data k is present in given BST) in a list. Return empty list otherwise.

Note: Assume that BST contains all unique elements.

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
Time Limit: 1 second   
Sample Input 1:
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
2


Sample Output 1:
2 5 8
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
bool getPathHelper(BinaryTreeNode<int> *root, int data, vector<int>& result) {
    if (root == NULL) {
        return false;
    }
    if (root->data == data) {
        result.push_back(root->data);
        return true;
    }
    // Check in the left subtree
    if (getPathHelper(root->left, data, result)) {
        result.push_back(root->data);
        return true;
    }
    // Check in the right subtree
    if (getPathHelper(root->right, data, result)) {
        result.push_back(root->data);
        return true;
    }
    return false;
}

vector<int>* getPath(BinaryTreeNode<int> *root, int data) {
    vector<int>* result = new vector<int>();
    if (getPathHelper(root, data, *result)) {
        return result;
    } else {
        delete result; // Clean up if no path is found
        return nullptr;
    }
}