/***********************************************************

Problem statement
For a given postorder and inorder traversal of a Binary Tree of type integer stored in an array/list, create the binary tree using the given two arrays/lists. You just need to construct the tree and return the root.

Note:
Assume that the Binary Tree contains only unique elements. 
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= N <= 10^4
Where N is the total number of nodes in the binary tree.

Time Limit: 1 sec
Sample Input 1:
7
4 5 2 6 7 3 1 
4 2 5 1 6 3 7 
Sample Output 1:
1 
2 3 
4 5 6 7 
Sample Input 2:
6
2 9 3 6 10 5 
2 6 3 9 5 10 
Sample Output 2:
5 
6 10 
2 3 
9 
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
#include <unordered_map>
BinaryTreeNode<int>* buildTreeHelper(int* postorder, int postStart, int postEnd, int* inorder, int inStart, int inEnd, unordered_map<int, int>& inorderIndexMap) {
    if (postStart > postEnd || inStart > inEnd) {
        return NULL;
    }

    int rootData = postorder[postEnd];
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);

    int rootIndexInInorder = inorderIndexMap[rootData];
    int leftSubtreeSize = rootIndexInInorder - inStart;

    root->left = buildTreeHelper(postorder, postStart, postStart + leftSubtreeSize - 1, inorder, inStart, rootIndexInInorder - 1, inorderIndexMap);
    root->right = buildTreeHelper(postorder, postStart + leftSubtreeSize, postEnd - 1, inorder, rootIndexInInorder + 1, inEnd, inorderIndexMap);

    return root;
}

BinaryTreeNode<int>* buildTree(int* postorder, int postLength, int* inorder, int inLength) {
    unordered_map<int, int> inorderIndexMap;
    for (int i = 0; i < inLength; i++) {
        inorderIndexMap[inorder[i]] = i;
    }
    return buildTreeHelper(postorder, 0, postLength - 1, inorder, 0, inLength - 1, inorderIndexMap);
}