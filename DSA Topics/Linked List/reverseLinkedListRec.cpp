/****************************************************************
Problem statement
Given a singly linked list of integers, reverse it using recursion and return the head to the modified list. You have to do this in O(N) time complexity where N is the size of the linked list.

 Note :
No need to print the list, it has already been taken care. Only return the new head to the list.
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1 :
1
1 2 3 4 5 6 7 8 -1
Sample Output 1 :
8 7 6 5 4 3 2 1
Sample Input 2 :
2
10 -1
10 20 30 40 50 -1
Sample Output 2 :
10 
50 40 30 20 10 
*****************************************************************/

// Node *reverseLinkedListRec(Node *head)
// {
//     //Write your code here
// 	Node *current = head;
// 	Node *previous = NULL;
// 	Node *nextNode = NULL;

// 	while(current!=NULL)
// 	{
// 		nextNode = current->next;
// 		current->next = previous;
// 		previous = current;
// 		current = nextNode;
// 	}
// 	return previous;
// }


Node *reverseLinkedListRec(Node *head)

{
	if(head==NULL||head->next==NULL)
	return head;

	Node *smallreversedList = reverseLinkedListRec(head->next);

	Node *lastNode  = smallreversedList;
	while(lastNode->next!=NULL)
	{
		lastNode = lastNode->next;
	}
	lastNode ->next = head;
	head->next = NULL;

	return smallreversedList;
}

