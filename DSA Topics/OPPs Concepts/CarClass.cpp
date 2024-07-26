#include <iostream>
#include <string>

using namespace std;

class Car {
private:
    int price; // Added this to fix the reference to price in DisplayCarDetails()

public:
    string name;
    int ManfacturedYear;

    void addCar(string name,int price, int ManfacturedYear)
    {
        this->name = name;
        this->price = price;
        this->ManfacturedYear = ManfacturedYear;
        cout<<"Car added in collection"<<endl;
    }

    void DisplayCarDetails() {
        cout << "Car Name: " << name << endl;
        cout << "Car Price: " << price << endl;
        cout << "Car Manufactured Year: " << ManfacturedYear << endl;
    }

// Default Constructor
    Car()
    {
        name = "Undefiend";
        price = 0;
        ManfacturedYear =0000;
        cout<<"Default Constructor called"<<endl;
    }

    // Constructor to initialize the variables
    Car(string name, int carPrice, int carManufacturedYear) {
        this->name = name;
        price = carPrice;
        ManfacturedYear = carManufacturedYear;
    }
};
