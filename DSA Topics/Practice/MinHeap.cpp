#include<iostream>
using namespace std;

class minHeap()
{
    public:
    int size = 0;
    vector<int>heap;

    int getMin()
    {
        if(size!=0)
        {
            return heap[0];
        }
        else
        {
            cout<<"Heap is empty"<<endl;
            return -1;
        }
    }

    void Hepify()
    {
        int childIndex = size-1;

        while(childIndex>0)
        {
            int parentIndex = (childIndex-1)/2;
            if(heap[parentIndex]> heap[childIndex])
            {
                swap(heap[parentIndex], heap[childIndex]);
                childIndex = parentIndex;
            }
            else
            {
                break;
            }
            childIndex = parentIndex;

        }

        return;

    }

    void DownHepify()
    {
       int i = 0;

    while (true) {
        int childIndex1 = (2 * i) + 1; // Left child
        int childIndex2 = (2 * i) + 2; // Right child
        int smallest = i;

        if (childIndex1 < size && heap[childIndex1] < heap[smallest]) {
            smallest = childIndex1;
        }

        if (childIndex2 < size && heap[childIndex2] < heap[smallest]) {
            smallest = childIndex2;
        }

        if (smallest == i) {
            break;
        }

        swap(heap[i], heap[smallest]);

        i = smallest;
    }
        

    }

    void insert(int item)
    {
        heap.push_back(item);
        size++;
        Hepify();
        return;
    }

    void DeleteMin()
    {
        if(size!=0)
        {
           
            heap[0]= heap[size-1];
            heap.pop_back();
            size--;
            if(size!=1)
            DownHepify();

        }
        else
        {
            cout<<"Heap is empty";
        }

            return;
        
    }
};



int main()
{
    minHeap mh;

    mh.insert(10);
    mh.insert(15);
    mh.insert(20);
    mh.insert(17);
    mh.insert(8);

    cout << "Minimum Element: " << mh.getMin() << endl;

    mh.DeleteMin();
    cout << "Minimum Element after extracting min: " << mh.getMin() << endl;

    return 0;
}