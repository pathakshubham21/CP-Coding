/****************************************************************
 
Problem statement
For a given singly linked list of integers, arrange the nodes such that all the even number nodes are placed after the all odd number nodes. The relative order of the odd and even terms should remain unchanged.

Note :
1. No need to print the linked list, it has already been taken care. Only return the new head to the list.
2. Don't create a new linked list.
3.  Just change the data, instead rearrange the provided list.
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Where M is the size of the singly linked list.

Time Limit: 1sec
Sample Input 1 :
1
1 4 5 2 -1
Sample Output 1 :
1 5 4 2 
Sample Input 2 :
2
1 11 3 6 8 0 9 -1
10 20 30 40 -1
Sample Output 2 :
1 11 3 9 6 8 0
10 20 30 40

*****************************************************************/
Node* evenAfterOdd(Node* head) {
    if (!head) return head;

    Node* oddHead = NULL;
    Node* oddTail = NULL;
    Node* evenHead = NULL;
    Node* evenTail = NULL;
    Node* current = head;

    while (current) {
        if (current->data % 2 != 0) { // Odd node
            if (!oddHead) {
                oddHead = current;
                oddTail = oddHead;
            } else {
                oddTail->next = current;
                oddTail = oddTail->next;
            }
        } else { // Even node
            if (!evenHead) {
                evenHead = current;
                evenTail = evenHead;
            } else {
                evenTail->next = current;
                evenTail = evenTail->next;
            }
        }
        current = current->next;
    }

    if (oddTail) {
        oddTail->next = evenHead; // Connect the end of odd list to the start of even list
    }

    if (evenTail) {
        evenTail->next = NULL; // Ensure the last node of even list points to NULL
    }

    return oddHead ? oddHead : evenHead; // If no odd nodes, return evenHead
}