/************************************************************
 Problem statement
Given a generic tree, count and return the number of leaf nodes present in the given tree.

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
Time Limit: 1 sec
Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0 
Sample Output 1 :
4
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

int getLeafNodeCount(TreeNode<int>* root) {
    // Write your code here
     if (root == NULL) return NULL;

    queue<TreeNode<int>*>q;
    q.push(root);

    int TotalLeafNode = 0;
    while(q.size()!=0)
    {
        TreeNode<int> *frontNode = q.front();
        q.pop();
        if(frontNode->children.size()==0)
        {
            TotalLeafNode++;

        }
        int i=0;
        for(i=0;i<frontNode->children.size();i++)
        {
            q.push(frontNode->children[i]);
        }
    }
    return TotalLeafNode;
}