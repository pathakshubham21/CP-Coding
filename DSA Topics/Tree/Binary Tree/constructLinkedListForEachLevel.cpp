/**********************************************************
Problem statement
Given a binary tree, write code to create a separate linked list for each level. You need to return the array which contains head of each level linked list.

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
Time Limit: 1 second
Sample Input 1:
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output 1:
5 
6 10 
2 3 
9
	Following are the Binary Tree Node class structure and
	the Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public: 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this->data = data;
        	left = NULL;
        	right = NULL;
    	}
	};

	template <typename T>
	class Node {
		public:
    	T data;
    	Node<T> *next;
    	Node(T data) {
        	this->data=data;
        	this->next=NULL;
    	}
	};

***********************************************************/


vector<Node<int>*> constructLinkedListForEachLevel(BinaryTreeNode<int> *root) {
    vector<Node<int>*> ans;
    if (root == NULL) return ans;

    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    q.push(NULL); // Marker for end of level

    Node<int>* head = NULL;
    Node<int>* tail = NULL;

    while (!q.empty()) {
        BinaryTreeNode<int>* frontNode = q.front();
        q.pop();

        if (frontNode == NULL) {
            // End of current level
            ans.push_back(head);

            // If there are more nodes in the queue, start a new level
            if (!q.empty()) {
                q.push(NULL); // Add marker for next level
                head = NULL;
                tail = NULL;
            }
        } else {
            // Add the current node to the linked list
            Node<int>* newNode = new Node<int>(frontNode->data);
            if (head == NULL) {
                head = newNode;
                tail = head;
            } else {
                tail->next = newNode;
                tail = tail->next;
            }

            // Add children to the queue
            if (frontNode->left) {
                q.push(frontNode->left);
            }
            if (frontNode->right) {
                q.push(frontNode->right);
            }
        }
    }

    return ans;
}