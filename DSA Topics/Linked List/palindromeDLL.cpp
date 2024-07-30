/****************************************************************
 

 Problem statement
You have been given a head to a doubly linked list of integers. Write a function check to whether the list given is a 'Palindrome' or not.

Note:
There is no requirement for input or output handling. Your task is to implement a function that returns whether the given doubly linked list is a palindrome or not. The nodes in the doubly linked list are connected to its previous nodes using a 'prev' pointer in addition to the usual next pointer.
Detailed explanation ( Input/output format, Notes, Images )
 Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Time Limit: 1sec

Where 'M' is the size of the doubly linked list.
Sample Input 1 :
1
9 2 3 3 2 9 -1
Sample Output 1 :
true
Sample Input 2 :
2
0 2 3 2 5 -1
-1
Sample Output 2 :
false
true 



    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
			Node *prev;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
				this->prev = NULL;
	        }
        };

*****************************************************************/
bool palindromeDLL(Node* head){


	if(!head || head->next==NULL)
	return true;

	Node *left = head;
	Node *right   = NULL;

	Node *temp = head;
	while(temp->next!=NULL)
	{
		temp = temp->next;
	}

	right = temp;


	while(left!=right)
	{
		if(left->data!=right->data)
		return false;

		left = left->next;
		right = right->prev;
	}

	return true;
    
}