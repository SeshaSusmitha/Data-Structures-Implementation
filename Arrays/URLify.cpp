
/***************************************************************
Cracking the Coding Interview Q1.3 page no: 60

Program to URLify a given string. Spaces of the given string 
will be replaced with %20

******************************************************************/

#include <iostream>
using namespace std;

string URLify(string s);

int main()
{
	string s = "sesha susmitha yellamraju";

	s = URLify(s);
	cout<<"URLified string : "<<s<<endl;
}


string URLify(string s)
{
	int str_len = s.length();
	int count = 0, i, j = 0;
	
	/* Counts the length of given string */
	for(i = 0; i < str_len; i++)
	{
		if(s[i] == ' ')
			count++;
	}

	/* Finding the length of new string to be */
	int new_str_len = str_len + (2*count);

	/* Resize the string to the new length */
	s.resize(new_str_len);
	
	
	for(i = str_len-1; i >= 0; i--)
	{
		/* Replacing space with %20 and moving index accordingly */
		if(s[i] == ' ')
		{
			
			s[new_str_len-1] = '0';
			s[new_str_len-2] = '2';
			s[new_str_len-3] = '%';
			new_str_len = new_str_len - 3;
		}
		else
		{
			/* If not a space, just move character by 1 position */
			s[new_str_len-1] = s[i];
			new_str_len--;
		}
	}

	/* Return resized string*/
	return s;
}

