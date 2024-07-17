// Problem statement
// For a given input string(str), find and return the total number of words present in it.

// It is assumed that two words will have only a single space in between. Also, there wouldn't be any leading and trailing spaces in the given input string.

int countWords(string str) {
	// Write your code here

	int count=0;

	for(int i=0;i<str.length();i++)
	{
		if(str[i]==' ')
		count++;
	}

	return ++count;
}