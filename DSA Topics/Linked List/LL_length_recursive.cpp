// Problem statement
// Given a linked list, find and return the length of the given linked list recursively.

// Detailed explanation ( Input/output format, Notes, Images )
//  Constraints :
// 1 <= t <= 20
// 0 <= N <= 10^4
// Time Limit: 1 sec
// Sample Input 1:
// 1 
// 3 4 5 2 6 1 9 -1
// Sample Output 1:
// 7

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

int length(Node *head) {

	if(!head)
	{
		return 0;
	}

	return 1+length(head->next);

    // Write your code here
}