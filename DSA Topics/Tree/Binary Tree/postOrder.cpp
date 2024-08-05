/**********************************************************
	Problem statement
For a given Binary Tree of integers, print the post-order traversal.

ALTIMAGE

The postorder traversal for the given binary tree will be 40 50 20 30 10
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= N <= 10^6
Where N is the total number of nodes in the binary tree.

Time Limit: 1 sec
Sample Input 1:
1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
 Sample Output 1:
4 5 2 6 7 3 1 
Sample Input 2:
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
 Sample Output 1:
2 9 3 6 10 5 
	
	Following is the Binary Tree Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public : 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this -> data = data;
        	left = NULL;
        	right = NULL;
    	}
	};

***********************************************************/

void postOrder(BinaryTreeNode<int> *root) {
	// Write your code here
	if(root==NULL)
	return;
	postOrder(root->left);
	postOrder(root->right);
	cout<<root->data<<" ";

}

// void postOrder(BinaryTreeNode<int>* root) {
//     if (root == NULL) return;

//     stack<BinaryTreeNode<int>*> s1, s2;
//     s1.push(root);

//     while (!s1.empty()) {
//         BinaryTreeNode<int>* node = s1.top();
//         s1.pop();
//         s2.push(node);

//         // Push left and right children to the first stack
//         if (node->left) s1.push(node->left);
//         if (node->right) s1.push(node->right);
//     }

//     // Now print all nodes in s2 (reverse order of post-order traversal)
//     while (!s2.empty()) {
//         cout << s2.top()->data << " ";
//         s2.pop();
//     }
// }