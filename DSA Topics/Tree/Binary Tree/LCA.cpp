#include <iostream>
using namespace std;

bool helper(Node* root, Node* l1, Node* l2, int &count)
{
    if(root==NULL)
    {
        return false;
    }
    if(root->data==l1->data || root->data==l2->data)
    {
        count++;
    }
   return helper(root->left, item,count)||helper(root->right, item, count);
}

Node* LCS(Node *root, Node* l1, Node* l2)
{
    
    if(root==NULL)
    {
        return NULL;
    }
    
    int count = 0;
    
    bool temp= helper(root->left,l1,l2,count);
    
   if(count==2)
   {
       LCS(root->left,l1,l2);
   }
   else if(count==1)
   {
       return root;
   }
   else if(count==0)
   {
        LCS(root->right,l1,l2);
   }
    
}



// Best Solution 

bool LCSHelper(Node* root, Node* l1, Node* l2, Node* &result)
   
   {
       if(root==NULL)
    {
        return false;
    }
    
    if(root->data==l1->data)
    {
        return true;
    }
    
    if(root->data==l2->data)
    {
        return true;
    }
    
    bool l = LCSHelper(root->left,l1, l2, result);
    bool r = LCSHelper(root->right, l1, l2, result);
    
    if(l&r)
    {
        result = root;
    }
    
    return l||r;
    
    
    
   }
   
   Node* LCS(Node *root, Node* l1, Node* l2)
   
   {
       
       if(root==NULL)
       {
           return NULL;
       }
       
       Node *result;
       LCSHelper(root, l1, l2,result);
       return result;
   }

