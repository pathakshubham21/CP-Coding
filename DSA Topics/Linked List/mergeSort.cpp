/****************************************************************
 
Problem statement
 Given a singly linked list of integers, sort it using 'Merge Sort.'

Note :
No need to print the list, it has already been taken care. Only return the new head to the list.
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Where M is the size of the singly linked list.

Time Limit: 1sec
Sample Input 1 :
1
10 9 8 7 6 5 4 3 -1
Sample Output 1 :
 3 4 5 6 7 8 9 10 
 Sample Input 2 :
2
-1
10 -5 9 90 5 67 1 89 -1
Sample Output 2 :
-5 1 5 9 10 67 89 90 
}


*****************************************************************/
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

Node* findMiddle(Node* head) {
    if (!head) return head;

    Node* slow = head;
    Node* fast = head;

    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

Node* mergeSortHelper(Node* start, Node* end) {
    if (start == end) {
        start->next = NULL;  // Disconnect the next part to prevent cycles
        return start;
    }

    Node* mid = findMiddle(start);
    Node* nextToMid = mid->next;
    mid->next = NULL;  // Split the list into two halves

    Node* left = mergeSortHelper(start, mid);
    Node* right = mergeSortHelper(nextToMid, end);

    Node* sortedList = mergeTwoSortedLinkedLists(left, right);
    return sortedList;
}

Node* mergeSort(Node* head) {
    if (!head || !head->next) return head;

    Node* end = head;
    while (end->next != NULL) {
        end = end->next;
    }

    return mergeSortHelper(head, end);
}
