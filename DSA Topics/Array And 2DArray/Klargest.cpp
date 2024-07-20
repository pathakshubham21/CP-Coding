// You are given an unsorted array containing ‘N’ integers. You need to find ‘K’ largest elements from the given array and fill those K elements in the given output array.

// Note:
// We recommend you to use inbuilt function of cpp library.
// You don't need to return or print anything it has already been taken care of. Just implement the given function and fill the output array as required.
// Sample Input 1:
// 4 2
// 3 4 2 1
// 5 1
// 2 2 3 3 1
// Sample Output 1:
// 3 4
// 3

void Klargest(int arr[],int output[],int n,int k){

    sort(arr,arr+n);
    int j=0;
    n=n-1;
    while(k--)
    {
        output[j++]= arr[n--];
    }
    reverse(output,output+j);
    
}