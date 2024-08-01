#include<iostream>
#include<climits>
using namespace std;

class StackUsingArray
{
    int *data;
    int nextIndex;
    int capacity;


    public:

      StackUsingArray(int totalSize)
    {
        data = new int[totalSize];
        nextIndex = 0;
        capacity = totalSize;
    }

    void push(int element)
    {
        if(nextIndex==capacity)
        {
            cout<<"Stack Full"<<endl;
            return;
        }
        data[nextIndex] = element;
        nextIndex++;

    }
    void pop()
    {
        if(!isEmpty())
        {
            cout<<"Element deleted from Stack = "<<data[nextIndex-1]<<endl;
            nextIndex--;
        }
        else
        {
            cout<<"Stack is empty"<<endl;
        }

        return;

    }

    int top()
    {

        if(!isEmpty())
        {
            cout<<"Stack top Element = "<<data[nextIndex-1]<<endl;
            return data[nextIndex-1];
        }
        else
        {
            cout<<"Stack is empty"<<endl;
            return INT_MIN;
            
        }
        
    }
    bool isEmpty()
    {
        return nextIndex==0;
    }
    int size()
    {
        return nextIndex;
    }


};