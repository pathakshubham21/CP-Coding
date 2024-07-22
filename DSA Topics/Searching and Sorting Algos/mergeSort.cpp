// Problem statement
// You are given the starting 'l' and the ending 'r' positions of the array 'ARR'.



// You must sort the elements between 'l' and 'r'.



// Note:
// Change in the input array itself. So no need to return or print anything.
// Example:
// Input: ‘N’ = 7,
// 'ARR' = [2, 13, 4, 1, 3, 6, 28]

// Output: [1 2 3 4 6 13 28]


void mergeSortedArray(int arr[],int l, int r)
{
    int mid = (l+r)/2;
    int i= l;
    int j= mid+1;
    int k = 0;
    int *temp = new int[r-l+1];

    while(i<=mid&&j<=r)
    {
        if(arr[i]<arr[j])
        {
            temp[k++]= arr[i];
            i++;
        }
        else{
            temp[k++] = arr[j];
            j++;
        }
    }

    while(i<=mid)
    {
        temp[k++] = arr[i];
        i++;
    }
    while(j<=r)
    {
        temp[k++]= arr[j];
        j++;
    }
    int m = 0;
    while(m<k)
    {
        arr[l+m] = temp[m]; 
        m++;
    }

    delete temp;
    return;

}

void mergeSort(int arr[], int l, int r) {
    // Write Your Code Here

    if(l>=r)
    return;
    int mid = (l+r)/2;
    mergeSort(arr,l,mid);
    mergeSort(arr,mid+1,r);
    mergeSortedArray(arr,l,r);
}