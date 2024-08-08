/**********************************************************
   Problem statement
You are given a Binary Search Tree (BST) and a target value ‘K’. Your task is to return true if there exist two nodes in the given BST such that the sum of their values is equal to the given target ‘K’, else return false.



A binary search tree (BST) is a binary tree data structure which has the following properties.

• The left subtree of a node contains only nodes with data less than the node’s data.

• The right subtree of a node contains only nodes with data greater than the node’s data.

• Both the left and right subtrees must also be binary search trees.


Note:
1. All the elements of the Binary Search Tree are unique.

2. You can’t use the same node value/element of BST twice.


For example:
tree: 8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
'K' = 13,
   
    Following is the Binary Tree Node structure:

    class BinaryTreeNode
    {
    public:
        int data;
        BinaryTreeNode *left, *right;
        BinaryTreeNode() : data(0), left(NULL), right(NULL) {}
        BinaryTreeNode(int x) : data(x), left(NULL), right(NULL) {}
        BinaryTreeNode(int x, BinaryTreeNode *left, BinaryTreeNode *right) : data(x), left(left), right(right) {}
    };
***********************************************************/

bool find(BinaryTreeNode *root, int item) {
    if (root == NULL)
        return false;
    if (root->data == item)
        return true;
    return find(root->left, item) || find(root->right, item);
}

bool pairSumBstHelper(BinaryTreeNode *root_temp, BinaryTreeNode *root, int k) {
    if (root == NULL)
        return false;
    
    int complement = k - root->data;
    
    if (complement != root->data && find(root_temp, complement)) {
        return true;
    }

    return pairSumBstHelper(root_temp, root->left, k) || pairSumBstHelper(root_temp, root->right, k);
}

bool pairSumBst(BinaryTreeNode *root, int k) {
    return pairSumBstHelper(root, root, k);
}