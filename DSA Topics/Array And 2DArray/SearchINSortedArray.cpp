#include<iostream>
#include<vector>
using namespace std;

int first_half_helper(vector<int>&vec, int start, int end, int key)
{
    
    // 1, 2, 2 , 2, 2
    
    int mid=0;
    
    while(start<=end)
    {
        mid = (start+end)/2;
        // if(arr[right] ==key && arr[right-1]!=key mid==0 && vec[mid]==key)
        // {
        //     return mid;
        // }
        
        
        if(vec[mid]==key && (mid-1)>=0 && vec[mid-1]!=key)
        {
            return mid;
        }
        else if(vec[mid]==key)
        {
            right = mid-1;
        }
        else if(vec[mid]>key)
        {
            right = mid-1;
        }
        else
        {
            left = mid+1;
        }
        
    }
    
    return -1;
    
}

int second_half_helper(vector<int>&vec, int start, int end, int key)
{
      // 2, 2 , 3 ,4 ,5
    
    int mid;
    
    while(start<=end)
    {
        mid = (start+end)/2;
        
        if(vec[mid]==key && vec[mid+1]!=key)
        {
            return mid;
        }
        else if(vec[mid]==key)
        {
            left = mid+1;
        }
        else if(vec[mid]>key)
        {
            right = mid-1;
        }
        else
        {
            left = mid+1;
        }
        
    }
    
    return -1;
    
}

int main()
{
    
    int n;
    cin>>n;
    vector<int>vec(n);
    for(int i=0;i<n;i++)
    {
        cin>>vec[i];
    }
    int key;
    cin>>key;
    
    int key_found_index=-1;
    
    int left =0;
    int right = n-1;
    int mid;
    while(left<=right)
    {
        mid = (left+right)/2;
        
        if(vec[mid]==key)
        {
            key_found_index = mid;
            break;
        }
        else if(vec[mid]<key)
        {
            left = mid+1;
        }
        
        else
        {
            right = mid-1;
        }
        
    }
    
    if(!key_found_index)
    {
        cout<<"-1";
        return 0;
    }
    
    int first_oc = -1;
    int last_oc = -1;
    
    first_oc = first_half_helper(vec, 0, key_found_index, key);
    last_oc = second_half_helper(vec, key_found_index+1, n-1, key);
    
    if(first_oc!=-1 && last_oc!=-1 && last_oc!=first_oc)
    {
        cout<<"first "<<first_oc<<" "<<"Last "<<last_oc<<endl;
    }
    else
    {
        cout<<"Correct and is not possible "<<endl;
        cout<<"first "<<first_oc<<" "<<"Last "<<last_oc<<endl;
        
    }
    
    
    
    // 1 2 2 2 2 2 5 7
    // Ans : First = 1, Last = 5
    
    
    
}