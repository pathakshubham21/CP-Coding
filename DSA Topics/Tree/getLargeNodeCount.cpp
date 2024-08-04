/************************************************************
 

 Problem statement
Given a tree and an integer x, find and return the number of nodes which contains data greater than x.

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
Time Limit: 1 sec
Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0
35 
Sample Output 1 :
3
Sample Input 2 :
10 3 20 30 40 2 40 50 0 0 0 0
10 
Sample Output 2:
5


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
// int ans =0;
// int getLargeNodeCount(TreeNode<int>* root, int x) {
//     // Write your code here

//       if(root->data>x)
//         {
//             ans++;
//         }

//     for(int i=0;i<root->children.size();i++)
//     {
      

//             return getLargeNodeCount(root->children[i],x);
        
//     }

//     return ans;

// }

int getLargeNodeCount(TreeNode<int>* root, int x) {
    if (root == NULL) return 0;

    int ans = 0;
    if (root->data > x) {
        ans++;
    }

    for (int i = 0; i < root->children.size(); i++) {
        ans += getLargeNodeCount(root->children[i], x);
    }

    return ans;
}