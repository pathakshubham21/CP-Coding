/************************************************************
 Problem statement
Given a generic tree, print the input tree in level wise order.

For printing a node with data N, you need to follow the exact format -

N:x1,x2,x3,...,xn
where, N is data of any node present in the generic tree. x1, x2, x3, ...., xn are the children of node N. Note that there is no space in between.
You need to print all nodes in the level order form in different lines.

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
Time Limit: 1 sec
0 <= Data of a node <= 10^5
Sample Input 1:
10 3 20 30 40 2 40 50 0 0 0 0 


Sample Output 1:
10:20,30,40
20:40,50
30:
40:
40:
50:
            if(i<frontNode->children.size()-1)
            cout<<",";
        }
        cout<<endl;
    }
    // Write your code here
}





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
#include<queue>
void printLevelWise(TreeNode<int>* root) {

    if (root == NULL) return;

    queue<TreeNode<int>*>q;
    q.push(root);
    while(q.size()!=0)
    {
        TreeNode<int> *frontNode = q.front();
        q.pop();
        cout<<frontNode->data<<":";
        int i=0;
        for(i=0;i<frontNode->children.size();i++)
        {
            q.push(frontNode->children[i]);

            cout<<frontNode->children[i]->data;
            if(i<frontNode->children.size()-1)
            cout<<",";
        }
        cout<<endl;
    }
    // Write your code here
}



// void printLevelWise(TreeNode<int>* root) {
//     if (root == NULL) return;  // Handle edge case where the root is NULL

//     queue<TreeNode<int>*> q;
//     q.push(root);

//     while (!q.empty()) {
//         TreeNode<int>* frontNode = q.front();
//         q.pop();

//         // Print the current node's data
//         cout << frontNode->data << ":";

//         // Print all children of the current node
//         for (int i = 0; i < frontNode->children.size(); i++) {
//             cout << frontNode->children[i]->data;
//             if (i < frontNode->children.size() - 1) {
//                 cout << ",";  // Add comma between children
//             }
//             q.push(frontNode->children[i]);
//         }

//         cout << endl;  // Move to the next line after processing the current node
//     }
// }