#include <iostream>
#include <string>
#include "CarClass.cpp" // Including the Car class definition

using namespace std;

void checking()
{
 vector<int>vec(2,5, 6, 11, 15);
 int x = 11;
 
 int l, r, mid;

 while(l<=r)
 {
    mid= (l+r)/2;

    if(vec[mid]==x)
    {
        cout<<"Found at "<<mid<<;
        break;
    }
    else if(vec[mid]>x)
    {
        r= mid -1;

    }
    else 
    {
        l = mid+1;
    }

}

return;
}

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
