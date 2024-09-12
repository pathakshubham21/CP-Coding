// Given the head of a singly linked list and an integer k, split the linked list into k consecutive linked list parts.

// The length of each part should be as equal as possible: no two parts should have a size differing by more than one. This may lead to some parts being null.

// The parts should be in the order of occurrence in the input list, and parts occurring earlier should always have a size greater than or equal to parts occurring later.

// Return an array of the k parts.

 

// Example 1:


// Input: head = [1,2,3], k = 5
// Output: [[1],[2],[3],[],[]]
// Explanation:
// The first element output[0] has output[0].val = 1, output[0].next = null.
// The last element output[4] is null, but its string representation as a ListNode is [].
// Example 2:


// Input: head = [1,2,3,4,5,6,7,8,9,10], k = 3
// Input: head = [1,2,3,4,5,6,7,8,9,10], k = 3
// Output: [[1,2,3,4],[5,6,7],[8,9,10]]
// Explanation:
// The input has been split into consecutive parts with size difference at most 1, and earlier parts are a larger size than the later parts.




    vector<ListNode*> splitListToParts(ListNode* head, int k) {

    int size = 0;
    ListNode* ptr = head;

    
    while (ptr != NULL) {
        size++;
        ptr = ptr->next;
    }

   
    vector<ListNode*> result(k, NULL); 
    vector<int> inter(k, 0);  

    if (k >= size) {
       
        for (int i = 0; i < size; i++) {
            inter[i] = 1;  
        }
    } else {
       
        int rem = size % k;
        int initial_size = size / k;

        for (int i = 0; i < k; i++) {
            inter[i] = initial_size; 
        }

        int i = 0;
        while (rem > 0) {
            inter[i]++;  
            rem--;
            i++;
        }
    }

   
    ptr = head;
    for (int i = 0; i < k && ptr != NULL; i++) {
        result[i] = ptr;  
        int list_size = inter[i]; 

     
        for (int j = 1; j < list_size && ptr != NULL; j++) {
            ptr = ptr->next;
        }

     
        if (ptr != NULL) {
            ListNode* next_part = ptr->next;  
            ptr->next = NULL;  
            ptr = next_part;  
        }
    }

    return result;  
}