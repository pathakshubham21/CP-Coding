// Following is the Binary Tree node structure
/**************

Problem statement
Given the binary Tree and two nodes say ‘p’ and ‘q’. Determine whether the two nodes are cousins of each other or not. Two nodes are said to be cousins of each other if they are at same level of the Binary Tree and have different parents.

Do it in O(n).

Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= N <= 10^5

Sample Input :
5 6 10 2 3 4 -1 -1 -1 -1 9 -1 -1 -1 -1
2
4
Sample Output :
true
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
***************/
#include <vector>
#include <utility>
void heightHelper(BinaryTreeNode<int> *root, int p, int q,vector<pair<int,int>>&result,int currentHeight)
{
    if(root==NULL)
    return;

    if(root->data==p||root->data==q)
    {
        pair<int,int>temp;

        temp.first = root->data;
        temp.second = currentHeight;
        result.push_back(temp);
        return;
    }
    else{
        currentHeight++;
    }
     heightHelper(root->left,p,q,result,currentHeight);
     heightHelper(root->right,p,q,result,currentHeight);
     currentHeight--;
}

bool isCousin(BinaryTreeNode<int> *root, int p, int q) {
    // Write your code here
    if(root==NULL)
    return false;

    vector<pair<int,int>>result;
    heightHelper(root,p,q,result,0);
    // cout<<result[0].second<<" "<<result[1].second;
    if(result[0].second==result[1].second&& result[0].first!=result[1].first)
    return true;
    else
    return false;


}
