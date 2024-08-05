/************************************************************
Problem statement
Given a generic tree, find and return the node with second largest value in given tree.

Note: Return NULL if no node with required value is present.

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
Time Limit: 1 sec
Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0 
Sample Output 1 :
40

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
// #include<climits>
// TreeNode<int>* getSecondLargestNode(TreeNode<int>* root) {
//     // Write your code here

//      if (root == NULL) return root;

//     queue<TreeNode<int>*>q;
//     q.push(root);
//     TreeNode<int> *largest = new TreeNode<int>(INT_MIN);
//     TreeNode<int> *secondLargest =new TreeNode<int>(INT_MIN);
//     while(q.size()!=0)
//     {
//         TreeNode<int> *frontNode = q.front();
//         q.pop();
//         int i=0;
//         if(frontNode->data>largest->data)
//         {
//             secondLargest = largest;
//             largest = frontNode;
//         }
//         else if(frontNode->data>secondLargest->data){

//             secondLargest = frontNode;

//         }
//         for(i=0;i<frontNode->children.size();i++)
//         {
//             q.push(frontNode->children[i]);
//         }

       
//     }

//     return secondLargest;
// }

TreeNode<int>* getSecondLargestNode(TreeNode<int>* root) {
    if (root == NULL) return NULL;

    TreeNode<int>* largest = NULL;
    TreeNode<int>* secondLargest = NULL;

    queue<TreeNode<int>*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode<int>* frontNode = q.front();
        q.pop();

        if (largest == NULL || frontNode->data > largest->data) {
            secondLargest = largest;
            largest = frontNode;
        } else if ((secondLargest == NULL || frontNode->data > secondLargest->data) && frontNode->data < largest->data) {
            secondLargest = frontNode;
        }

        for (int i = 0; i < frontNode->children.size(); i++) {
            q.push(frontNode->children[i]);
        }
    }

    return secondLargest;
}