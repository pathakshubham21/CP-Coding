// Problem statement
// Implement the function RemoveMin for the min priority queue class.

// For a minimum priority queue, write the function for removing the minimum element present. Remove and return the minimum element.

// Note : main function is given for your reference which we are using internally to test the code.

// #include <vector>

// class PriorityQueue {
//     vector<int> pq;

//    public:
//     bool isEmpty() { 
//         return pq.size() == 0; 
//     }

//     int getSize() { 
//         return pq.size(); 
//     }

//     int getMin() {
//         if (isEmpty()) {
//             return 0;
//         }

//         return pq[0];
//     }

//     void insert(int element) {
//         pq.push_back(element);

//         int childIndex = pq.size() - 1;

//         while (childIndex > 0) {
//             int parentIndex = (childIndex - 1) / 2;

//             if (pq[childIndex] < pq[parentIndex]) {
//                 int temp = pq[childIndex];
//                 pq[childIndex] = pq[parentIndex];
//                 pq[parentIndex] = temp;
//             } else {
//                 break;
//             }

//             childIndex = parentIndex;
//         }
//     }

//     int removeMin() {
//         if(!getSize())
//         {
//             return -1;
//         }
//         int ans  = pq[0];
//         pq[0] = pq[pq.size()-1];
//         pq.pop_back();
//         int parentIndex = 0;
//         int leftChildIndex = 2*parentIndex+1;
//         int rightChildIndex = 2*parentIndex+2;
//         int minIndex = 0;
//         int pq_size = pq.size();
//                while (true) {
//             int leftChildIndex = 2 * parentIndex + 1;
//             int rightChildIndex = 2 * parentIndex + 2;
//             int minIndex = parentIndex;

//             if (leftChildIndex < pq_size && pq[leftChildIndex] < pq[minIndex]) {
//                 minIndex = leftChildIndex;
//             }

//             if (rightChildIndex < pq_size && pq[rightChildIndex] < pq[minIndex]) {
//                 minIndex = rightChildIndex;
//             }

//             if (minIndex == parentIndex) {
//                 break;
//             }

//             // Swap the parent with the minimum child
//             int temp = pq[parentIndex];
//             pq[parentIndex] = pq[minIndex];
//             pq[minIndex] = temp;

//             parentIndex = minIndex;
//         }

//         return ans;
//     }
 
// };

#include <vector>

class PriorityQueue {
    vector<int> pq;

   public:
    bool isEmpty() { 
        return pq.size() == 0; 
    }

    int getSize() { 
        return pq.size(); 
    }

    int getMin() {
        if (isEmpty()) {
            return 0;
        }

        return pq[0];
    }

    void insert(int element) {
        pq.push_back(element);

        int childIndex = pq.size() - 1;

        while (childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;

            if (pq[childIndex] < pq[parentIndex]) {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            } else {
                break;
            }

            childIndex = parentIndex;
        }
    }

    int removeMin() {
        if(!getSize())
        {
            return -1;
        }
        int ans  = pq[0];
        pq[0] = pq[pq.size()-1];
        pq.pop_back();
        int parentIndex = 0;
        int leftChildIndex = 2*parentIndex+1;
        int rightChildIndex = 2*parentIndex+2;
        int minIndex = 0;
        int pq_size = pq.size();
        while(true)
        {
            if(rightChildIndex<pq_size && pq[rightChildIndex]<pq[leftChildIndex] && pq[rightChildIndex]<pq[minIndex] )
            {
                int temp = pq[minIndex];
                pq[minIndex] = pq[rightChildIndex];
                pq[rightChildIndex] = temp;
                minIndex = rightChildIndex;
                leftChildIndex = 2*minIndex+1;
                rightChildIndex = 2*minIndex+2;
            }
            else if(leftChildIndex<pq_size&&pq[leftChildIndex]<pq[minIndex])
            {
                int temp = pq[minIndex];
                pq[minIndex] = pq[leftChildIndex];
                pq[leftChildIndex] = temp;
                minIndex = leftChildIndex;
                leftChildIndex = 2*minIndex+1;
                rightChildIndex = 2*minIndex+2;
            }
            else{
                break;
            }
        }
        return ans;
        // Write your code here
    }
};