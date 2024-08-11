/*************************************************************
Problem statement
You are given a preorder traversal of a binary search tree. Your task is to find the postorder from the preorder.



Return the root of the BST constructed from the given preorder. The driver code will then use this root to print the post-order traversal.



For example:
You are given preOrder = [10, 5, 1, 7, 40, 50], the binary search tree from the given preorder traversal is 
sample1

Hence the answer is [1, 7, 5, 50, 40, 10].
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1
6
8 5 1 7 10 12
Sample Output 1:
1 7 5 12 10 8 
Explanation:
preOrder = [8, 5, 1, 7, 10, 12], the binary search tree from the given preorder traversal is 
sample2

Hence the answer is [1, 5, 7, 10, 40, 50].
Sample Input 2:
3
1 3 2
Sample Output 2:
2 3 1 
Constraints:
 1 <= N <= 10^5
 1 <= preorder[i] <= 10^6

Time Limit: 1 sec.
    Following is the Binary Tree node structure
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*************************************************************/

#include<vector>

TreeNode* buildBSTFromPreorder(vector<int>& preOrder, int& index, int minVal, int maxVal) {
    // Base case: if the index is out of bounds or the current value is out of the valid range
    if (index >= preOrder.size() || preOrder[index] < minVal || preOrder[index] > maxVal) {
        return NULL;
    }

    // The current value is within the valid range, create a new node
    int currentValue = preOrder[index];
    TreeNode* root = new TreeNode(currentValue);
    index++; // Move to the next value in the preorder array

    // Recursively build the left and right subtrees with updated value ranges
    root->left = buildBSTFromPreorder(preOrder, index, minVal, currentValue - 1);
    root->right = buildBSTFromPreorder(preOrder, index, currentValue + 1, maxVal);

    return root;
}

void postOrderTraversal(TreeNode* root, vector<int>& postOrder) {
    if (root == NULL) {
        return;
    }
    // Traverse the left subtree
    postOrderTraversal(root->left, postOrder);
    // Traverse the right subtree
    postOrderTraversal(root->right, postOrder);
    // Visit the root node
    postOrder.push_back(root->data);
}

TreeNode* preOrderTree(vector<int>& preOrder) {
    int index = 0;
    TreeNode* root = buildBSTFromPreorder(preOrder, index, INT_MIN, INT_MAX);
    return root;
}

vector<int> getPostOrderFromPreOrder(vector<int>& preOrder) {
    TreeNode* root = preOrderTree(preOrder);
    vector<int> postOrder;
    postOrderTraversal(root, postOrder);
    return postOrder;
}
