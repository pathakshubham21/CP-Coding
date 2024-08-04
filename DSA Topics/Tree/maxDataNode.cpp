/************************************************************
 Problem statement
Given a generic tree, find and return the node with maximum data. You need to return the node which is having maximum data.

Return null if tree is empty.

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
Time Limit: 1 sec
Sample Input 1:
10 3 20 30 40 2 40 50 0 0 0 0 
Sample Output 1:
50
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
#include<climits>
TreeNode<int>* maxDataNode(TreeNode<int>* root) {
    // Write your code here
           if (root == NULL) return NULL;

    queue<TreeNode<int>*>q;
    q.push(root);

    TreeNode<int> *maxNode; 
    int max = INT_MIN;
    while(q.size()!=0)
    {
        TreeNode<int> *frontNode = q.front();
        q.pop();
        if(frontNode->data>max)
        {
            max = frontNode->data;
            maxNode = frontNode;

        }
        int i=0;
        for(i=0;i<frontNode->children.size();i++)
        {
            q.push(frontNode->children[i]);
        }
    }
    return maxNode;
}