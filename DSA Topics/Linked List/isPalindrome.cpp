// You have been given a head to a singly linked list of integers. Write a function check to whether the list given is a 'Palindrome' or not.

// Detailed explanation ( Input/output format, Notes, Images )
//  Constraints :
// 1 <= t <= 10^2
// 0 <= M <= 10^5
// Time Limit: 1sec

// Where 'M' is the size of the singly linked list.
// Sample Input 1 :
// 1
// 9 2 3 3 2 9 -1
// Sample Output 1 :
// true
// Sample Input 2 :
// 2
// 0 2 3 2 5 -1
// -1
// Sample Output 2 :
// false
// true


Node* reverseList(Node *head) {
    Node *prev = NULL;
    Node *current = head;
    Node *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}
bool compareLists(Node *head1, Node *head2) {
    while (head1 != NULL && head2 != NULL) {
        if (head1->data != head2->data)
            return false;
        head1 = head1->next;
        head2 = head2->next;
    }
    return true;
}

bool isPalindrome(Node *head) {
    if (head == NULL || head->next == NULL)
        return true;

    // Find the middle of the list
    Node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse the second half of the list
    Node *secondHalf = reverseList(slow);

    // Compare the first half and the reversed second half
    bool result = compareLists(head, secondHalf);

    // Restore the list (optional)
    reverseList(secondHalf);

    return result;
}