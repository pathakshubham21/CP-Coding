#include <iostream>
#include <string>
#include "CarClass.cpp" // Including the Car class definition

using namespace std;

int main() {
    // Creating an object of the Car class
    Car myCar1;
    myCar1.addCar("Toyota", 20000, 2021);
    myCar1.DisplayCarDetails();
    
    Car myCar2;

    myCar2.addCar("Audi",100,2024);
    myCar2.DisplayCarDetails();

    cout<<"Printing all car Cleaction"<<endl;
    myCar1.DisplayCarDetails();
    myCar2.DisplayCarDetails();



    return 0;
}
