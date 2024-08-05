/************************************************************
Problem statement
Given a generic tree, find and return the node for which sum of its data and data of all its child nodes is maximum. In the sum, data of the node and data of its immediate child nodes has to be taken.

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
Time Limit: 1 sec
0 < Node's val <= 10^5
Sample Input 1 :
5 3 1 2 3 1 15 2 4 5 1 6 0 0 0 0


Sample Output 1 :
1


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

TreeNode<int>* maxSumNode(TreeNode<int>* root) {
    // Write your code here

        if (root == NULL) return root;

    queue<TreeNode<int>*>q;
    q.push(root);
    int maxSum =0;
    TreeNode<int> *ansNode =root;
    while(q.size()!=0)
    {
        TreeNode<int> *frontNode = q.front();
        q.pop();
        int i=0;
        int tempmaxSum =0;
        for(i=0;i<frontNode->children.size();i++)
        {
            tempmaxSum+= frontNode->children[i]->data;
            q.push(frontNode->children[i]);
        }

        if(tempmaxSum>maxSum)
        {
            maxSum = tempmaxSum;
            ansNode = frontNode;
        }
       
    }

    return ansNode;
}