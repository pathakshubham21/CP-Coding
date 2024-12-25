#include<iostream>
using namespace std;

class TreeNode
{
    public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void PrintTree(TreeNode *root)
{
    if(root==NULL)
    {
        return;
    }
    PrintTree(root->left);
    cout<<root->data<<" ";
    PrintTree(root->right);
}

TreeNode* InsertNode(TreeNode *root, int val)
{
    if(root==NULL)
    {
        return new TreeNode(val);
    }
    if(root->data < val)
    {
        root->right = InsertNode(root->right, val);
    }
    else
    {
        root->left = InsertNode(root->left, val);
    }  
    return root;
}

// TreeNode* DeleteNode(TreeNode* root, int val)
// {
//     if(root==NULL)
//     return NULL;

//     if(root->data < val)
//     {
//         root->right =  DeleteNode(root->left, val);
//         return root;
//     }
//     else if(root->data, val)
//     {
//         root->left = DeleteNode(root->right, val);
//         return root;
//     }

//     if(root->left == NULL)
//     {
//         TreeNode *temp =  root->right;
//         delete root;
//         return temp;
//     }
//     else if(root->right==NULL){

//         TreeNode *temp = root->left;
//         delete root;
//         return temp;
//     }
//     else{

//         TreeNode *s = root->right;
//         TreeNode *sp = root;
//         while(s->left!-NULL)
//         {
//             sp =s;
//             s = s->left;
//         }

//         if(s = sp)
//         {
//             sp->right = s->right;
//         }
//         else{
//             sp ->left  = s->right;
//         }
//         root->data = s->data;
//         delete s;
//         return root;
//     }


// }

void path(TreeNode *root, vector<int>&result, int key)
{
    if(root==NULL)
    {
        result.clear();
    return;
    }

    if(root->data==key)
    {
        result.push_back(root->data);
        return;
    }
    else if(root->data>key)
    {
        result.push_back(root->data);
        path(root->left, result, key);
        
    }
    else if(root->data<key)
    {
        result.push_back(root->data);
        path(root->right, result, key); 
    }

}


int main()
{

    TreeNode *root = NULL;
    root = InsertNode(root, 35);
    root = InsertNode(root, 20);
    root = InsertNode(root, 40);
    root = InsertNode(root, 15);
    root = InsertNode(root, 25);
    root = InsertNode(root, 50);
    root = InsertNode(root, 10);
    root = InsertNode(root, 19);
    root = InsertNode(root, 45);

    // PrintTree(root);

    vector<int>result;
    int key = 25;

  path(root, result, key);
    if(result.size()!=0)
    {

    for(int i=0;i<result.size();i++)
    {
        cout<<result[i]<<" ";
    }
    }
    else{
        cout<<"Path not exists";
    }




    return 0;
}