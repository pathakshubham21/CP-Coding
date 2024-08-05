/************************************************************

Problem statement
You are given a generic tree. You have to replace each node with its depth value. You just have to update the data of each node, there is no need to return or print anything.

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
Time Limit: 1 sec
Sample Input 1:
10 3 20 30 40 2 40 50 0 0 0 0 
Sample Output 1:
0 
1 1 1 
2 2

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
// int depth = 0;
// void replaceWithDepthValue(TreeNode<int>* root) {
//     // Write your code here
//     root->data = depth;
//     depth++;

//     for(int i=0;i<root->children.size();i++)
//     {
//         replaceWithDepthValue(root->children[i]);
//         depth--;
//     }

// }

void replaceWithDepthValueHelper(TreeNode<int>* root, int depth) {
    if (root == NULL) return;

    // Set the current node's data to the depth
    root->data = depth;

    // Recursively update the depth for all child nodes
    for (int i = 0; i < root->children.size(); i++) {
        replaceWithDepthValueHelper(root->children[i], depth + 1);
    }
}

void replaceWithDepthValue(TreeNode<int>* root) {
    // Start the helper function with depth 0 for the root
    replaceWithDepthValueHelper(root, 0);
}