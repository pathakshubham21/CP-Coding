// Problem statement
// For a given a singly linked list of integers and a position 'i', print the node data at the 'i-th' position.

//  Note :
// Assume that the Indexing for the singly linked list always starts from 0.

// If the given position 'i',  is greater than the length of the given singly linked list, then don't print anything.
// Detailed explanation ( Input/output format, Notes, Images )
//  Constraints :
// 1 <= t <= 10^2
// 0 <= N <= 10^5
// i  >= 0
// Time Limit: 1sec
// Sample Input 1 :
// 1
// 3 4 5 2 6 1 9 -1
// 3
// Sample Output 1 :
// 2
// Sample Input 2 :
// 2
// 3 4 5 2 6 1 9 -1
// 0
// 9 8 4 0 7 8 -1
// 3
// Sample Output 2 :
// 3
// 0

	int IndexCounter = 0;

	while(head!=NULL)
	{
          if (IndexCounter == i) {
            cout << head->data;
            return;
          }
		  IndexCounter++;



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

void printIthNode(Node *head, int i)
{

	int IndexCounter = 0;

	while(head!=NULL)
	{
          if (IndexCounter == i) {
            cout << head->data;
            return;
          }
		  IndexCounter++;

		  head= head->next;
        }

		return;
    //Write your code here
}