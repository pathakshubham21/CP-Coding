/************************************************************
Problem statement
You are given a ‘Binary Tree’.



Return the preorder traversal of the Binary Tree.



Example:
Input: Consider the following Binary Tree:
Example

Output: 
Following is the preorder traversal of the given Binary Tree: [1, 2, 5, 3, 6, 4]


Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
1 2 3 5 4 6 7 -1 -1 -1 -1 -1 -1 -1 -1


 Sample Output 1:
1 2 5 4 3 6 7


Explanation of Sample Input 1:
The Binary Tree given in the input is as follows:
Sample1

Sample Input 2:
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1


 Sample Output 2:
5 6 2 3 9 10


Explanation of Sample Input 2:
The Binary Tree given in the input is as follows:
Sample2

Expected Time Complexity:
Try to do this in O(n).


Constraints:
1 <= n <= 100000
where 'n' is the number of nodes in the binary tree.

Time Limit: 1 sec


    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
void preOrderHelper(TreeNode<int> * root, vector<int>&result)
{
    if(root==NULL)
    return;

    result.push_back(root->data);
    preOrderHelper(root->left,result);
    preOrderHelper(root->right,result);
}
vector<int> preOrder(TreeNode<int> * root){
    // Write your code here.
    vector<int> result;
    preOrderHelper(root,result);

    return result;
   

}

// vector<int> preOrder(TreeNode<int>* root) {
//     vector<int> result;
//     if (root == NULL) return result;

//     // Use a stack to simulate the recursion process
//     stack<TreeNode<int>*> s;
//     s.push(root);

//     while (!s.empty()) {
//         TreeNode<int>* current = s.top();
//         s.pop();

//         result.push_back(current->data);

//         // Push right child first so that left child is processed first
//         if (current->right) s.push(current->right);
//         if (current->left) s.push(current->left);
//     }

//     return result;
// }
