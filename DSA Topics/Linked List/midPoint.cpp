// Problem statement
// For a given singly linked list of integers, find and return the node present at the middle of the list.

// Note :
// If the length of the singly linked list is even, then return the first middle node.

// Example: Consider, 10 -> 20 -> 30 -> 40 is the given list, then the nodes present at the middle with respective data values are, 20 and 30. We return the first node with data 20.
// Detailed explanation ( Input/output format, Notes, Images )
// Constraints :
// 1 <= t <= 10^2
// 0 <= M <= 10^5 
// Where M is the size of the singly linked list.

// Time Limit: 1sec
// Sample Input 1 :
// 1
// 1 2 3 4 5 -1
// Sample Output 1 :
// 3
// Sample Input 2 :
// 2 
// -1
// 1 2 3 4 -1
// Sample Output 2 :
// 2
//         fast = fast->next->next;
//     }

//     return slow;
//     // Write your code here
// }

Node *midPoint(Node *head)
{

    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
    // Write your code here
}