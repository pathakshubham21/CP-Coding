// Problem statement
// Given a singly linked list of integers and position 'i', delete the node present at the 'i-th' position in the linked list recursively.

//  Note :
// Assume that the Indexing for the linked list always starts from 0.

// No need to print the list, it has already been taken care. Only return the new head to the list.
// Detailed explanation ( Input/output format, Notes, Images )
// Constraints :
// 1 <= t <= 10^2
// 0 <= M <= 10^5
// Where M is the size of the singly linked list.
// 0 <= i < M

// Time Limit:  2 sec
// Sample Input 1 :
// 1
// 3 4 5 2 6 1 9 -1
// 3
// Sample Output 1 :
// 3 4 5 6 1 9
// Sample Input 2 :
// 2
// 30 -1
// 0
// 10 20 30 50 60 -1
// 4
// Sample Output 2 :
// 10 20 30 50 



/****************************************************************
 
    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/

Node *deleteNodeRec(Node *head, int pos) 
{
   if (head == NULL) {
        return NULL; // If the list is empty or position is invalid
    }
    if (pos == 0) {
        Node *temp = head->next;
        delete head; // Delete the current head
        return temp; // Return the new head
    }
    head->next = deleteNodeRec(head->next, pos - 1);
    return head;
}