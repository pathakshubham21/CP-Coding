// Problem statement
// You are given a Singly Linked List of integers. Return true if it has a cycle, else return false.

// A cycle occurs when a node's next points back to a previous node in the list.

// Example:
// In the given linked list, there is a cycle, hence we return true.
// Sample Example 1

// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input 1 :
// 1 2 3 4 -1
// 1


Sample Output 1 :
true
bool detectCycle(Node *head)
{
    if(!head||head->next==NULL)
    return false;
	//	Write your code here
    Node *slow = head;
    Node *fast = head;
    while(fast->next!=NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast)
        return true;
    }
    return false;
}