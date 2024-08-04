/************************************************************
 Problem statement
Given a generic tree, find and return the height of given tree. The height of a tree is defined as the longest distance from root node to any of the leaf node. Assume the height of a tree with a single node is 1.

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
Time Limit: 1 sec
Sample Input 1:
10 3 20 30 40 2 40 50 0 0 0 0 
Sample Output 1:
3
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

int getHeight(TreeNode<int>* root) {
    if (root == NULL) return 0;

    queue<TreeNode<int>*> q;
    q.push(root);
    q.push(NULL);

    int height = 1;  // Start height from 1 as a single node has height 1

    while (!q.empty()) {
        TreeNode<int>* frontNode = q.front();
        q.pop();

        if (frontNode == NULL) {
            if (!q.empty()) {
                q.push(NULL);  // Push NULL to mark end of the next level
                height++;
            }
        } else {
            for (int i = 0; i < frontNode->children.size(); i++) {
                q.push(frontNode->children[i]);
            }
        }
    }

    return height;
}