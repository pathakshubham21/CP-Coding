// Problem statement
// You have been given a linked list of integers. Your task is to write a function that deletes a node from a given position, 'POS'.

// Note :
// Assume that the Indexing for the linked list always starts from 0.

// If the position is greater than or equal to the length of the linked list, you should return the same linked list without any change.
// Sample Input 1 :
// 3 4 5 2 6 1 9 -1
// 3
// Sample Output 1 :
// 3 4 5 6 1 9
// Explanation of Sample Output 1 :
// The data in the node with index 3 is 2 which has been removed.
// Sample Input 2 :
// 3 4 5 2 6 1 9 -1
// 0
// Sample Output 2 :
// 4 5 2 6 1 9

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

Node *deleteNode(Node *head, int pos)
{
	if(head==NULL)
	return NULL;

 if (pos == 0) {
        Node *newHead = head->next;
        delete head;
        return newHead;
    }
	
	Node *temp =head;
	int i=0;
	while(i<pos-1&&temp->next!=NULL)
	{
		temp=temp->next;
		i++;
	}

        if (temp->next != NULL) {
                Node *del = temp->next;
                temp->next = temp->next->next;
                delete del;
        }

        return head;


    // Write your code here.
}
