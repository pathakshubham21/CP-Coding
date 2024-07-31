/****************************************************************
 
Problem statement
You have been given a singly linked list of integers along with two integers, 'i,' and 'j.' Swap the nodes that are present at the 'i-th' and 'j-th' positions and return the new head to the list.

Note :
1. Remember, You need to swap the nodes, not only the data.
2. Indexing starts from 0.
3. No need to print the list, it has already been taken care.
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Where M is the size of the singly linked list.
0 <= i < M
0 <= j < M

Time Limit: 1sec
Sample Input 1 :
1
3 4 5 2 6 1 9 -1
3 4
Sample Output 1 :
3 4 5 6 2 1 9 
 Sample Input 2 :
2
10 20 30 40 -1
1 2
70 80 90 25 65 85 90 -1
0 6
 Sample Output 2 :
10 30 20 40 
90 80 90 25 65 85 70 

*****************************************************************/
Node *swapNodes(Node *head, int i, int j) {
    if (!head || head->next == NULL || i == j)
        return head;

    Node *dummy = new Node(0);
    dummy->next = head;
    Node *prevNode1 = dummy, *prevNode2 = dummy;
    Node *node1 = head, *node2 = head;

    // Find the (i-1)th and (j-1)th nodes
    for (int index = 0; index < i; ++index) {
        prevNode1 = node1;
        node1 = node1->next;
    }
    for (int index = 0; index < j; ++index) {
        prevNode2 = node2;
        node2 = node2->next;
    }

    // Swap the nodes
    if (prevNode1->next == prevNode2) {
        // Case when i and j are consecutive
        prevNode1->next = node2;
        node1->next = node2->next;
        node2->next = node1;
    } else if (prevNode2->next == prevNode1) {
        // Case when j and i are consecutive
        prevNode2->next = node1;
        node2->next = node1->next;
        node1->next = node2;
    } else {
        // General case
        Node *temp = node2->next;
        prevNode1->next = node2;
        node2->next = node1->next;
        prevNode2->next = node1;
        node1->next = temp;
    }

    head = dummy->next;
    delete dummy;
    return head;
}