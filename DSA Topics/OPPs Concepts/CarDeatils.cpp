#include <iostream>
#include <string>
#include "CarClass.cpp" // Including the Car class definition

using namespace std;

int main() {
    // Creating an object of the Car class
    Car myCar("Toyota", 20000, 2021);
    myCar.Display();
    
    return 0;
}
