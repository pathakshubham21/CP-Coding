/**********************************************************
For a given Binary Tree of type integer and a number K, print out all root-to-leaf paths where the sum of all the node data along the path is equal to K.

Example:
alt txt

If you see in the above-depicted picture of Binary Tree, we see that there are a total of two paths, starting from the root and ending at the leaves which sum up to a value of K = 13.

The paths are:
a. 2 3 4 4
b. 2 3 8

One thing to note here is, there is another path in the right sub-tree in reference to the root, which sums up to 13 but since it doesn't end at the leaf, we discard it.
The path is: 2 9 2(not a leaf)
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
2 3 9 4 8 -1 2 4 -1 -1 -1 6 -1 -1 -1 -1 -1
13
 Sample Output 1:
2 3 4 4 
2 3 8
Sample Input 2:
5 6 7 2 3 -1 1 -1 -1 -1 9 -1 -1 -1 -1
13
 Sample Output 2:
5 6 2
5 7 1
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
#include<vector>
void findPaths(BinaryTreeNode<int> *node, int k, vector<int> &path, int currentSum) {
    if (node == NULL) {
        return;
    }

    // Add the current node to the path
    path.push_back(node->data);
    currentSum += node->data;

    // Check if it is a leaf node and sum of the path equals k
    if (node->left == NULL && node->right == NULL) {
        if (currentSum == k) {
            // Print the path
            for (int i = 0; i < path.size(); ++i) {
                cout << path[i] << (i < path.size() - 1 ? " " : "\n");
            }
        }
    } else {
        // Recur for left and right subtrees
        findPaths(node->left, k, path, currentSum);
        findPaths(node->right, k, path, currentSum);
    }

    // Backtrack by removing the current node from the path
    path.pop_back();
}

void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k) {
    vector<int> path;
    findPaths(root, k, path, 0);
}