/****************************************************************
 
Problem statement
You have been given two sorted(in ascending order) singly linked lists of integers.

Write a function to merge them in such a way that the resulting singly linked list is also sorted(in ascending order) and return the new head to the list.

Note :
Try solving this in O(1) auxiliary space.

No need to print the list, it has already been taken care.
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= t = 10^2
0 <= N <= 10 ^ 4
0 <= M <= 10 ^ 4
Where N and M denote the sizes of the singly linked lists. 

Time Limit: 1sec
Sample Input 1 :
1
2 5 8 12 -1
3 6 9 -1
Sample Output 1 :
2 3 5 6 8 9 12 
Sample Input 2 :
2
2 5 8 12 -1
3 6 9 -1
10 40 60 60 80 -1
10 20 30 40 50 60 90 100 -1
Sample Output 2 :
2 3 5 6 8 9 12 
10 10 20 30 40 40 50 60 60 60 80 90 100
*****************************************************************/

// Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2)
// {
//     Node *firstNode = NULL;
// 	Node *taleNode = NULL;

// 	if(!head1)
// 	return head2;

// 	if(!head2)
// 	return head1;

// 	firstNode = (head1->data)<(head2->data)?head1:head2;
// 	taleNode = firstNode;
// 	if(taleNode->data==head1->data)
// 	head1 = head1->next;
// 	else
// 		head2= head2->next;

// 	while(head1!=NULL&&head2!=NULL)
// 	{
// 		if(head1->data<head2->data)
// 		{
// 			taleNode->next = head1;
// 			taleNode = taleNode->next;
// 			head1= head1->next;
			
// 		}
// 		else{
// 			taleNode->next = head2;
// 			taleNode = taleNode->next;
// 			head2 = head2->next;
// 		}
// 	}

// 	taleNode->next = head1==NULL?head2:head1;

// 	return firstNode;

	

// }

Node* mergeTwoSortedLinkedLists(Node* head1, Node* head2) {
    if (!head1) return head2;
    if (!head2) return head1;

    Node* firstNode = NULL;
    Node* tailNode = NULL;

    if (head1->data < head2->data) {
        firstNode = head1;
        head1 = head1->next;
    } else {
        firstNode = head2;
        head2 = head2->next;
    }

    tailNode = firstNode;

    while (head1 != NULL && head2 != NULL) {
        if (head1->data < head2->data) {
            tailNode->next = head1;
            tailNode = head1;
            head1 = head1->next;
        } else {
            tailNode->next = head2;
            tailNode = head2;
            head2 = head2->next;
        }
    }

    tailNode->next = (head1 == NULL) ? head2 : head1;

    return firstNode;
}
