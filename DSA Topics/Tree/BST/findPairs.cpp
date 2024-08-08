#include <unordered_set>
  
void findPairs(BinaryTreeNode<int>* root, int sum, unordered_set<int>& set) {
    if (!root) return;

    // Traverse the left subtree
    findPairs(root->left, sum, set);

    // Check if the complement (sum - current node's data) exists in the set
    int complement = sum - root->data;
    if (set.find(complement) != set.end()) {
        // Print the pair with the smaller element first
        if (root->data < complement)
            cout << root->data << " " << complement << endl;
        else
            cout << complement << " " << root->data << endl;
    }

    // Add the current node's data to the set
    set.insert(root->data);

    // Traverse the right subtree
    findPairs(root->right, sum, set);
}

void pairSum(BinaryTreeNode<int>* root, int sum) {
    unordered_set<int> set; // To store nodes that have been visited
    findPairs(root, sum, set);
}