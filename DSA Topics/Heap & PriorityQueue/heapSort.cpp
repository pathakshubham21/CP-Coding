// Problem statement
// Given an integer array of size N. Sort this array (in decreasing order) using heap sort.

// Note: Space complexity should be O(1).

// Detailed explanation ( Input/output format, Notes, Images )
// Constraints :
// 1 <= n <= 10^6
// Time Limit: 1 sec
// Sample Input 1:
// 6 
// 2 6 8 5 4 3
// Sample Output 1:
// 8 6 5 4 3 2


using namespace std;
void heapSort(int pq[], int n) {
    // Write your code
    if(n==1)
    {
        return;
    }

    for(int i=1;i<n;i++)
    {
        int maxIndex = i;
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


    int size = n;
    while(size>0)
    {
    int parentIndex = 0;
    int leftChildIndex = 2*parentIndex+1;
    int rightChildIndex = 2*parentIndex+2;
    int maxIndex = 0;
    while(true)
    {
        if(rightChildIndex<size && pq[rightChildIndex]>pq[leftChildIndex] && pq[rightChildIndex]>pq[maxIndex] )
        {
            int temp = pq[maxIndex];
            pq[maxIndex] = pq[rightChildIndex];
            pq[rightChildIndex] = temp;
            maxIndex = rightChildIndex;
            leftChildIndex = 2*maxIndex+1;
            rightChildIndex = 2*maxIndex+2;
        }
        else if(leftChildIndex<size&&pq[leftChildIndex]>pq[maxIndex])
        {
            int temp = pq[maxIndex];
            pq[maxIndex] = pq[leftChildIndex];
            pq[leftChildIndex] = temp;
            maxIndex = leftChildIndex;
            leftChildIndex = 2*maxIndex+1;
            rightChildIndex = 2*maxIndex+2;
        } else {
            break;
        }
    }
    int temp = pq[0];
    pq[0] = pq[size-1];
    pq[size-1] = temp;
    size--;
    }
    int i=0;
    int j=n-1;
    // reverse array to print in decrising order
    while(i<=j)
    {
        int temp = pq[i];
        pq[i] = pq[j];
        pq[j]= temp;
        i++;
        j--;
    }

    return;
}