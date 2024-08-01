#include<iostream>
#include "StackUsingArray.cpp"
using namespace std;

int main()
{
    StackUsingArray stack1(5);

    stack1.push(1);
    stack1.push(2);
    stack1.push(3);

    stack1.push(4);
    stack1.push(5);
    stack1.push(6);

    stack1.pop();
    stack1.isEmpty();
    stack1.top();
    stack1.pop();
    stack1.push(11);
    stack1.pop();
    stack1.pop();
    stack1.pop();
    stack1.pop();
    stack1.pop();
    stack1.pop();

    return 0;


    

}
