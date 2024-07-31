/**
Problem statement
You are given a linked list having ‘n’ nodes and an integer ‘k’.



You have to rotate the linked list to the right by ‘k’ positions .



Example :
Input: linked list = [1 2 3 4] , k = 2

Output: 3 4 1 2

Explanation:
We have to rotate the given linked list to the right 2 times. After rotating it to the right once it becomes 4->1->2->3. After rotating it to the right again, it becomes 3->4->1->2. 


Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1 :
6
1 2 3 4 5 6
2


Sample Output 1 :
5 6 1 2 3 4


Explanation For Sample Input 1 :
For the first test case, after 1st clockwise rotation the modified linked list will be : 6->1->2->3->4->5
After, 2nd clockwise rotated the modified linked list will be : 5->6->1->2->3->4.
Thus the output is: 5 6 1 2 3 4.
 */

Node *rotate(Node *head, int k) {
     // Write your code here.
     if(head==NULL||head->next==NULL||k==0)
     return head;


     Node *LastNode = head;
     Node *KthNode = head;
     int lenght =1;

     while(LastNode->next!=NULL)
     {
          LastNode = LastNode->next;
          lenght++;
     }
     if(lenght == k)
     return head;
     else
     k = k%lenght;

     if(k==0)
     return head;
     int lastKthNodeIndex= lenght-k-1; // Becouse KthNode is alreday on head 
     while(lastKthNodeIndex--)
     {
          KthNode = KthNode->next;
     }

     Node *tempHead = head;
     head = KthNode->next;
     KthNode ->next = NULL;
     LastNode ->next = tempHead;

     return head;




}