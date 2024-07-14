// Problem statement
// You have been given two sorted arrays/lists(ARR1 and ARR2) of size N and M respectively, merge them into a third array/list such that the third array is also sorted.

void merge(int arr1[], int size1, int arr2[], int size2, int ans[])
{

    int size3 = size1+size2;

    int i,j;
    i=0;
    j=0;
    int k= 0;

    while(i<size1&&j<size2)
    {
        if(arr1[i]<arr2[j])
        {
            ans[k] = arr1[i];
            i++;
            k++;
        }
        else{
            ans[k] = arr2[j];
            j++;
            k++;
        }
    }

    if(i<size1)
    {
        for(int x =i;x<size1;x++)
        {
            ans[k] = arr1[x];
            k++;
        }
    }
    else if(j<size2)
    {

         for(int x =j;x<size2;x++)
        {
            ans[k] = arr2[x];
            k++;
        }

    }
    
    //Write your code here   
    //You don't have to print or return anything, 
    //just store the final answer in third array ans. 
}

