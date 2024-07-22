// Problem statement
// Given the 'start' and the 'end'' positions of the array 'input'. Your task is to sort the elements between 'start' and 'end' using quick sort.



// Note :
// Make changes in the input array itself.
// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input 1 :
// 6 
// 2 6 8 5 4 3
// Sample Output 1 :
// 2 3 4 5 6 8
// Sample Input 2 :
// 5
// 1 2 3 5 7
// Sample Output 2 :
// 1 2 3 5 7 

/*
	The function is called with the parameters:
	quickSort(input, 0, size - 1);

*/
#include<algorithm>
int partitionArray(int input[], int start, int end) {

	 int pivot = input[start];
    int countSmall = 0;

    for (int i = start + 1; i <= end; i++) {
        if (input[i] < pivot) {
            countSmall++;
        }
    }

    int PI = start + countSmall;
    swap(input[start], input[PI]);

    int i = start, j = end;
    while (i < PI && j > PI) {
        if (input[i] <input[PI]) {
            i++;
        } else if (input[j] > input[PI]) {
            j--;
        } else {
            swap(input[i], input[j]);
            i++;
            j--;
        }
    }

    return PI;

	// Write your code here
}

void quickSort(int input[], int start, int end) {
	/*
		Don't write main().
		Don't read input, it is passed as function argument.
		Change in the given array itself.
		Taking input and printing output is handled automatically.
	*/
   if (start >= end) {
        return;
    }

    int PI = partitionArray(input, start, end);
    quickSort(input, start, PI - 1);
    quickSort(input, PI + 1, end);

}