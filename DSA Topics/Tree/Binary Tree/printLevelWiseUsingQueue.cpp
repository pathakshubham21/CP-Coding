/**********************************************************
Problem statement
For a given a Binary Tree of type integer, print it in a level order fashion where each level will be printed on a new line. Elements on every level will be printed in a linear fashion and a single space will separate them.

Example:
alt txt

For the above-depicted tree, when printed in a level order fashion, the output would look like:

10
20 30 
40 50 60
Where each new line denotes the level in the tree.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= N <= 10^5
Where N is the total number of nodes in the binary tree.

Time Limit: 1 sec
Sample Input 1:
10 20 30 40 50 -1 60 -1 -1 -1 -1 -1 -1 
Sample Output 1:
10 
20 30 
40 50 60 
Sample Input 2:
8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
Sample Output 2:
8 
3 10 
1 6 14 
4 7 13 
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
#include<queue>
void printLevelWise(BinaryTreeNode<int> *root) {
    // Write your code here

	if(root==NULL)
	return;
	if(root->left==NULL && root->right==NULL)
	{
		cout<<root;
		return;
	}
	queue<BinaryTreeNode<int>*>q;
	q.push(root);
	q.push(NULL);

	while(q.size()!=0)
	{
		
		BinaryTreeNode<int> *frontNode = q.front();
		if(frontNode==NULL && q.size()==1)
		return;
		if(frontNode==NULL)
		{
			cout<<endl;
			q.push(NULL);
			q.pop();
			continue;
		}
		q.pop();
		cout<<frontNode->data<<" ";
		if(frontNode->left)
		q.push(frontNode->left);
		if(frontNode->right)
		q.push(frontNode->right);
		

	}

}