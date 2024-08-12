// Problem statement
// Implement the class for Max Priority Queue which includes following functions -



// 1. getSize -
// Return the size of priority queue i.e. number of elements present in the priority queue.



// 2. isEmpty -
// Check if priority queue is empty or not. Return true or false accordingly.



// 3. insert -
// Given an element, insert that element in the priority queue at the correct position.



// 4. getMax -
// Return the maximum element present in the priority queue without deleting. Return -Infinity if priority queue is empty.



// 5. removeMax -
// Delete and return the maximum element present in the priority queue. Return -Infinity if priority queue is empty.



// Note : main function is given for your reference which we are using internally to test the class.

#include<vector>
class PriorityQueue {
    vector<int>pq;

   public:
    PriorityQueue() {
        // Implement the constructor here
    }

    /**************** Implement all the public functions here ***************/

    void insert(int element) {
        pq.push_back(element);
        int maxIndex = pq.size()-1;
        int parentIndex = (maxIndex-1)/2;;
        while(parentIndex>=0)
        {
            parentIndex = (maxIndex-1)/2;
            if(pq[maxIndex]>pq[parentIndex])
            {
                int temp = pq[maxIndex];
                pq[maxIndex] = pq[parentIndex];
                pq[parentIndex]= temp;
                maxIndex = parentIndex;
            }
            else{
                break;
            }
        }
    }

    int getMax() {
        if(!isEmpty())
       return pq[0];
       return -1;
    }

    int removeMax() {
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
        int maxIndex = 0;
        int pq_size = pq.size();
        while(true)
        {
            if(rightChildIndex<pq_size && pq[rightChildIndex]>pq[leftChildIndex] && pq[rightChildIndex]>pq[maxIndex] )
            {
                int temp = pq[maxIndex];
                pq[maxIndex] = pq[rightChildIndex];
                pq[rightChildIndex] = temp;
                maxIndex = rightChildIndex;
                leftChildIndex = 2*maxIndex+1;
                rightChildIndex = 2*maxIndex+2;
            }
            else if(leftChildIndex<pq_size&&pq[leftChildIndex]>pq[maxIndex])
            {
                int temp = pq[maxIndex];
                pq[maxIndex] = pq[leftChildIndex];
                pq[leftChildIndex] = temp;
                maxIndex = leftChildIndex;
                leftChildIndex = 2*maxIndex+1;
                rightChildIndex = 2*maxIndex+2;
            }
            else{
                break;
            }
        }
        return ans;
    }

    int getSize() { 
        return pq.size();
    }

    bool isEmpty() {
        return pq.size()==0;
    }
};