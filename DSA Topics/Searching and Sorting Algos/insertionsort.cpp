void insertionSort(int arr[], int n)
{
    //write your code here

    int current;


    for(int i=1;i<n;i++)
    {
        current = arr[i];
           int j;
        for(j=i-1;j>=0;j--)
        {
            if(current < arr[j])
            {
                arr[j+1] = arr[j];
            }
            else{
                break;
            }
        }
        arr[j+1] = current;
    }
}