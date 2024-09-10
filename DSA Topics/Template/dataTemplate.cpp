#include <iostream>
using namespace std;

// Template class A
template <typename T>
class A
{
public:
    T a;
    T b;

    // Method to add two numbers
    void add(T num1, T num2)
    {
        T sum = num1 + num2;
        cout << sum << endl;
    }
};

int main()
{
    // Create an object of class A with int type
    A<int> obj;
    obj.add(22, 33);  // This will work fine with integers

    // Create another object
    A<double> obj2;   // Instantiate with double type
    obj2.add(22.2, 33.5);  // Pass two floating-point values

    return 0;
}
