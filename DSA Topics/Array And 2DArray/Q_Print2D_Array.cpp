#include <iostream>
using namespace std;

void print2DArray(int input[][1000], int row, int col) {
	// Write your code here

	int n= row;

	int k= n;
	int t=0;
	while(n>0)
	{
		k=n;
// K print n times each row
		while(k--)
		{
		for(int i=t;i<row;i++)
		{
                  for (int j = 0; j < col; j++) {
                    cout << input[i][j]<<" ";
                  }
				  cout<<endl;
                  break;
				  
                }
        }
		n--;
		t++;

	}


}

