#include<iostream>
#include "Tamplet_Class.cpp"
using namespace std;

int main()
{
    Template_Class<int> T1;
    cout<<"Creating template int type "<<endl;
    T1.setX(10);
    T1.setY(15);
    cout << "X value is : " << T1.getX() << endl;
    cout << "Y value is : " << T1.getY() << endl;

    Template_Class<double> T2;
    cout<<"Creating template double type "<<endl;
    T2.setX(10.123);
    T2.setY(15.45);
    cout << "X value is : " << T2.getX() << endl;
    cout << "Y value is : " << T2.getY() << endl;
    return 0;
}
