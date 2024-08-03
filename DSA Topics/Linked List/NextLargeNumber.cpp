/**********
 * 
 * Problem statement
Given a large number represented in the form of a linked list. Write code to increment the number by 1 in-place(i.e. without using extra space).

Note: You don't need to print the elements, just update the elements and return the head of updated LL. Input Constraints:
1 <= Length of Linked List <=10^6.
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1 :
3 9 2 5 -1
Sample Output 1 :
3 9 2 6
Sample Input 2 :
9 9 9 -1
Sample Output 1 :
1 0 0 0 
 * Following is the Node class that is already written.
 
class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};
 
*********/
Node *reverse(Node *head)
{
    if(head==NULL||head->next==NULL)
    return head;

    Node *curr = head;
    Node *prev = NULL;
    Node *nex =NULL;

    while(curr!=NULL)
    {
        nex = curr->next;
        curr->next = prev;
        prev = curr;
        curr= nex;

    }
    return prev;
}
Node* NextLargeNumber(Node *head) {

    if(!head)
    return head;
    if(head->next==NULL)
    {
        head->data = head->data+1;
        return head;
    }


    Node *temp = head;
    Node *prev=NULL;

    while(temp!=NULL)
    {
        prev = temp;
        temp= temp->next;
    }
    prev->data = prev->data+1;

    Node* realhead = head;

    if(prev->data==10)
    {
        head = reverse(realhead);
       int carry = 1;
        head->data =0;

        head=head->next;
        while(head!=NULL)
        {
            if(head->data==9)
            {
                head->data = 0;
                carry= 1;
            }
            else{

                head->data = head->data+carry;
                carry = 0;

            }

            prev = head;
            head= head->next;
        }
        if(carry==1)
        {
        Node* newNode = new Node(carry);
        prev->next = newNode;  
        newNode->next = NULL;          

        }

        head = reverse(realhead);
    }
    
    return head;
    
}


