// Problem statement
// Ninja has been given a binary string ‘STR’ containing either ‘0’ or ‘1’. A binary string is called beautiful if it contains alternating 0s and 1s.

// For Example:‘0101’, ‘1010’, ‘101’, ‘010’ are beautiful strings.

// He wants to make ‘STR’ beautiful by performing some operations on it. In one operation, Ninja can convert ‘0’ into ‘1’ or vice versa.

// Your task is to determine the minimum number of operations Ninja should perform to make ‘STR’ beautiful.

// For Example :
// Minimum operations to make ‘STR’ ‘0010’ beautiful is ‘1’. In one operation, we can convert ‘0’ at index ‘0’ (0-based indexing) to ‘1’. The ‘STR’ now becomes ‘1010’ which is a beautiful string. 



int makeBeautiful(string str) {
	// Write your code here
	int countZeroFirst = 0;
	int countOneFirst = 0;

	for(int i=0;i<str.length();i++)
	{
		if(i%2==0)
		{
			if(str[i]=='1')
			{
				countZeroFirst++;
			}
		}
		else{
			if(str[i]=='0')
			{
				countZeroFirst++;
			}
		}
	}
		for(int i=0;i<str.length();i++)
	{
		if(i%2==0)
		{
			if(str[i]=='0')
			{
				countOneFirst++;
			}
		}
		else{
			if(str[i]=='1')
			{
				countOneFirst++;
			}
		}
	}

	return min(countOneFirst,countZeroFirst);
}