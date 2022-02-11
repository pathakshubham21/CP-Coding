#include<iostream>
#include<vector>
using namespace std;

/* Every number reprents the index , idea is to make every element negative to their
 respective index and number is already negative the duplicate element this itself.
 */


int helper(vector<int>vec)
{
    for(int i=0;i<vec.size();i++)
    {
        if(vec[vec[i]]>0)
        {
            vec[vec[i]]=vec[vec[i]]*(-1);
        }
        else{
            return vec[i]*(-1);
        }
    }
    return -1;
}

int main()
{
    int n;
    cin>>n;
    vector<int>vec;
    for(int i=0;i<n;i++)
    {
        int data;
        cin>>data;
        vec.push_back(data);
    }

    int result;
    result = helper(vec);
    cout<<result;
    return 0;





}