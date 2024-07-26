#include <iostream>
#include <string>
#include "CarClass.cpp" // Including the Car class definition

using namespace std;

int main() {
    // Creating an object of the Car class
    Car myCar1("Toyota", 20000, 2021);
    myCar1.Display();
    
    Car myCar2;
    myCar2.Display();

    myCar2.addCar("Audi",100,2024);

    cout<<"Printing all car Cleaction"<<endl;
    myCar1.Display();
    myCar2.Display();



    return 0;
}
