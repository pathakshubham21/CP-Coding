#include<iostream>
using namespace std;
int tower_of_hanoi(int n,int from,int to,int aux)
{
    if(n==1)
    {
        cout<<"move disk " << n << " from rod " << from << " to rod " << to <<endl;
        return 1;

    }

    int x = tower_of_hanoi(n-1,from,aux,to);
    cout << "move disk " << n << " from rod " << from << " to rod " << to << endl;
    int y= tower_of_hanoi(n-1,aux,to,from);

    return (x+y+1);
}



int main()
{
    int number_of_disk;
    cin>>number_of_disk;
    int total_steps =0;
    total_steps = tower_of_hanoi(number_of_disk,1,3,2);
    cout<<"Total steps " <<total_steps;


}