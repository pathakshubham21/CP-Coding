// Problem statement
// Given the head of a singly linked list of integers, find and return its length.


// Example:
// Sample Linked List

// The length of the list is 4. Hence we return 4.

// Note:
// Exercise caution when dealing with edge cases, such as when the head is NULL. Failing to handle these edge cases appropriately may result in a runtime error in your code.


// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input 1 :
// 3 4 5 2 6 1 9 -1


// Sample Output 1 :
// 7


/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node()
            {
                this->data = 0;
                next = NULL;
            }
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
            Node(int data, Node* next)
            {
                this->data = data;
                this->next = next;
            }
        };


*****************************************************************/

int length(Node *head)
{
    int count=0;

    while(head!=NULL)
    {
        count++;
        head=head->next;
    }
	//Write your code here
    return count;
}