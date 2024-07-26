#include <iostream>
#include <string>

using namespace std;

class Car {
private:
    int model;
    int price; // Added this to fix the reference to price in Display()

public:
    string name;
    int ManfacturedYear;

    void Display() {
        cout << "Car Name: " << name << endl;
        cout << "Car Price: " << price << endl;
        cout << "Car Manufactured Year: " << ManfacturedYear << endl;
    }

    // Constructor to initialize the variables
    Car(string carName, int carPrice, int carManufacturedYear) {
        name = carName;
        price = carPrice;
        ManfacturedYear = carManufacturedYear;
    }
};
