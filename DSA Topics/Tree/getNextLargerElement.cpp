/************************************************************
 
 Problem statement
Given a generic tree and an integer n. Find and return the node with next larger element in the tree i.e. find a node with value just greater than n.

Note: Return NULL if no node is present with the value greater than n.

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
Time Limit: 1 sec
Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0 
18
Sample Output 1 :
20
Sample Input 2 :
10 3 20 30 40 2 40 50 0 0 0 0 
21
Sample Output 2:
30
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
TreeNode<int>* getNextLargerElementHelper(TreeNode<int>* root, int x,int nextLargest,TreeNode<int>* ans)
{

    if(root->data>x&&root->data<nextLargest)
    {
        nextLargest = root->data;
        ans = root;
        return ans;
    }

      for (int i = 0; i < root->children.size(); i++) 
    {
        ans = getNextLargerElementHelper(root->children[i],x,nextLargest,ans);
    }

    return ans;

}
TreeNode<int>* getNextLargerElement(TreeNode<int>* root, int x) {


    if(root==NULL)
    return NULL;
    int nextLargest = INT_MAX;
    TreeNode<int>* ans =NULL;

    ans  = getNextLargerElementHelper(root, x,nextLargest,ans);

    return ans;


    // Write your code here
}