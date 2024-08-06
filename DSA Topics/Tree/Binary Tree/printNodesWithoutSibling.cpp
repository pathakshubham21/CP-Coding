/************************************************************
Problem statement
For a given Binary Tree of type integer, print all the nodes without any siblings.

Example Input :
1 4 5 6 -1 -1 7 20 30 80 90 -1 -1 -1 -1 -1 -1 -1 -1
Explanation:
The input tree when represented in a two-dimensional plane, it would look like this:     
alt txt

In respect to the root, node data in the left subtree that satisfy the condition of not having a sibling would be 6, taken in a top-down sequence. Similarly, for the right subtree, 7 is the node data without any sibling.

Since we print the siblings in the left-subtree first and then the siblings from the right subtree, taken in a top-down fashion, we print 6 7.
Example Output:
6 7  
Detailed explanation ( Input/output format, Notes, Images )
 Constraints:
1 <= N <= 10^5
Where N is the total number of nodes in the binary tree.

Time Limit: 1 second
Sample Input 1:
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output 1:
9    
    Following is the Binary Tree node structure

    template <typename T>
    class BinaryTreeNode
    {
        public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data)
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

void printNodesWithoutSibling(BinaryTreeNode<int> *root) {
    // Write your code here

    if(root==NULL)
    return;

    if(root->left==NULL||root->right==NULL)
    {
        if(root->left!=NULL)
        {
            cout<<root->left->data<<" ";
        }
        else if(root->right!=NULL){
            cout<<root->right->data<<" ";
        }
    }
 printNodesWithoutSibling(root->left);
 printNodesWithoutSibling(root->right);

}

// void printNodesWithoutSibling(BinaryTreeNode<int> *root) {
//     // Base case: If the node is NULL, return
//     if(root == NULL)
//         return;

//     // If a node has only one child, print that child
//     if(root->left == NULL && root->right != NULL) {
//         cout << root->right->data << " ";
//     }
//     else if(root->right == NULL && root->left != NULL) {
//         cout << root->left->data << " ";
//     }

//     // Recur for left and right children
//     printNodesWithoutSibling(root->left);
//     printNodesWithoutSibling(root->right);
// }