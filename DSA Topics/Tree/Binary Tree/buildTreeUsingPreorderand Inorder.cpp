#include <unordered_map>
// Problem statement
// For a given preorder and inorder traversal of a Binary Tree of type integer stored in an array/list, create the binary tree using the given two arrays/lists. You just need to construct the tree and return the root.

// Note:
// Assume that the Binary Tree contains only unique elements. 
// Detailed explanation ( Input/output format, Notes, Images )
// Constraints:
// 1 <= N <= 10^3
// Where N is the total number of nodes in the binary tree.

// Time Limit: 1 sec
// Sample Input 1:
// 7
// 1 2 4 5 3 6 7 
// 4 2 5 1 6 3 7 
// Sample Output 1:
// 1 
// 2 3 
// 4 5 6 7 
// Sample Input 2:
// 6
// 5 6 2 3 9 10 
// 2 6 3 9 5 10 
// Sample Output 2:
// 5 
// 6 10 
// 2 3 
// 9 


BinaryTreeNode<int>* buildTreeHelper(int* preorder, int preStart, int preEnd, int* inorder, int inStart, int inEnd, unordered_map<int, int>& inorderIndexMap) {
    if (preStart > preEnd || inStart > inEnd) {
        return NULL;
    }
    
    int rootData = preorder[preStart];
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    
    int rootIndexInInorder = inorderIndexMap[rootData];
    int leftSubtreeSize = rootIndexInInorder - inStart;
    
    root->left = buildTreeHelper(preorder, preStart + 1, preStart + leftSubtreeSize, inorder, inStart, rootIndexInInorder - 1, inorderIndexMap);
    root->right = buildTreeHelper(preorder, preStart + leftSubtreeSize + 1, preEnd, inorder, rootIndexInInorder + 1, inEnd, inorderIndexMap);
    
    return root;
}

BinaryTreeNode<int>* buildTree(int* preorder, int preLength, int* inorder, int inLength) {
    unordered_map<int, int> inorderIndexMap;
    for (int i = 0; i < inLength; i++) {
        inorderIndexMap[inorder[i]] = i;
    }
    return buildTreeHelper(preorder, 0, preLength - 1, inorder, 0, inLength - 1, inorderIndexMap);
}
