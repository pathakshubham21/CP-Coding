// Problem statement
// Given a binary search tree and an integer.Find the floor value of a key in a binary search tree .

// (If k lies in BST then is floor equal to k,else floor is equal to previous greater value) Note: k would never be less than the minimum element of tree.
// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input 1:
// 4
// 8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
// Sample Output 1:
// 2
// Sample Input 2:
// 7
// 8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
// Sample Output 2:
// 7


int Floor(BinaryTreeNode<int> *root, int input)
{
    if (root == NULL)
        return INT_MIN;  // Return INT_MIN to indicate no valid floor found

    int floorValue = INT_MIN;  // Initialize floorValue to INT_MIN
    
    while (root != NULL) {
        if (root->data == input) {
            return root->data;  // Exact match, return immediately
        }
        if (root->data < input) {
            floorValue = root->data;  // Update floorValue if root->data is less than input
            root = root->right;       // Move to right subtree to find a closer floor value
        } else {
            root = root->left;        // Move to left subtree to find a smaller value
        }
    }

    return floorValue;  // Return the floor value found
}