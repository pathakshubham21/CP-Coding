#include <iostream>
#include<string>
using namespace std;

// int subs(string input, string output[]) {
// 	if (input.empty()) {
// 		output[0] = "";
// 		return 1;
// 	}

// 	string smallString = input.substr(1);
// 	int smallOutputSize = subs(smallString, output);
// 	for (int i = 0; i < smallOutputSize; i++) {
// 		output[i + smallOutputSize] = input[0] + output[i];
// 	}
// 	return 2 * smallOutputSize;
// }

int subs(string input,string output,int size,int index)
{
    if(index==size)
    {
        cout<<output<<endl;
        return 1;
    }
    int res=subs(input,output+input[index],size,index+1) + subs(input,output,size,index+1);
    return res;
}

int main() {
	string input= "ABC";
    cout<<subs(input,"",input.length(),0);
    return 0;
	
}
