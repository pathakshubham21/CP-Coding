/**********************************************************
Problem statement
Given a binary search tree and data of two nodes, find 'LCA' (Lowest Common Ancestor) of the given two nodes in the BST.

LCA
LCA of two nodes A and B is the lowest or deepest node which has both A and B as its descendants. 
Example:
In this example, the green coloured node is the LCA to A and B.
Alt Text

Note:
It is defined that each node is a descendant to itself, so, if there are two nodes X and Y and X has a direct connection from Y, then Y is the lowest common ancestor.
Example:
Alt Text

Note:

1. If out of 2 nodes only one node is present, return that node. 
2. If both are not present, return -1.
3. all the node data will be unique.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
Time Limit: 1 second
Sample Input 1:
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
2 10
Sample Output 1:
8
Sample Input 2:
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
2 6
Sample Output 2:
5
Sample Input 3:
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
12 78
Sample Output 3:
-1
    // If only one of the recursive calls returns a non-negative value, return that value
    // because it indicates that both val1 and val2 are found in that subtree
    return (leftLCA != -1) ? leftLCA : rightLCA;
}


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
int getLCA(BinaryTreeNode<int>* root, int val1, int val2) {
    // Base case: if the root is null, return -1 (indicating LCA not found)
    if (root == NULL) {
        return -1;
    }

    // If the current node matches either val1 or val2, return the current node's data
    if (root->data == val1 || root->data == val2) {
        return root->data;
    }

    // Recursively find LCA in the left and right subtrees
    int leftLCA = getLCA(root->left, val1, val2);
    int rightLCA = getLCA(root->right, val1, val2);

    // If both leftLCA and rightLCA are non-negative, it means val1 is in one subtree
    // and val2 is in the other, so the current node is the LCA
    if (leftLCA != -1 && rightLCA != -1) {
        return root->data;
    }

    // If only one of the recursive calls returns a non-negative value, return that value
    // because it indicates that both val1 and val2 are found in that subtree
    return (leftLCA != -1) ? leftLCA : rightLCA;
}
