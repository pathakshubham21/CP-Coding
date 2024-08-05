/************************************************************
 Problem statement
Given two generic trees, return true if they are structurally identical. Otherwise return false.

Structural Identical
If the two given trees are made of nodes with the same values and the nodes are arranged in the same way, then the trees are called identical.  
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
Time Limit: 1 sec
Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0 
10 3 20 30 40 2 40 50 0 0 0 0
Sample Output 1 :
true
Sample Input 2 :
10 3 20 30 40 2 40 50 0 0 0 0 
10 3 2 30 40 2 40 50 0 0 0 0
Sample Output 2:
false

    Following is the structure for the TreeNode class

    template <typename T>
    class TreeNode {
     public:
        T data;
        vector<TreeNode<T>*> children;
    
        TreeNode(T data) {
            this->data = data;
        }
    
        ~TreeNode() {
            for (int i = 0; i < children.size(); i++) {
                delete children[i];
            }
        }
    };

************************************************************/
bool areIdentical(TreeNode<int> *root1, TreeNode<int> * root2) {
    // Write your code here
   if (root1 == NULL && root2 == NULL) return true;  // Both trees are empty
    if (root1 == NULL || root2 == NULL) return false; // One tree is empty, and the other is not

    // Check if current nodes and their children count are identical
    if (root1->data != root2->data || root1->children.size() != root2->children.size()) {
        return false;
    }

    for (int i = 0; i < root1->children.size(); i++) {
        if (!areIdentical(root1->children[i], root2->children[i])) {
            return false; 
        }
    }

    return true;
}