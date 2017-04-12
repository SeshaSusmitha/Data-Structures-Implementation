/*********************************************************
Cracking the coding interview Q1.4 page no: 60
***********************************************************/


#include <iostream>
using namespace std;

int main()
{
	string s = "tact coabb";
	int asci_list[256];
	int count = 0;

	/* Calculates the count of each character of the string */
	for(int i : s)
		asci_list[i]++;

	for(int i = 0; i < s.length(); i++)
	{
		/* If a space is found, it just moves to the next character */
		if(s[i] == ' ')
			i++;

		/* Checks the no of occurences of each character. For a string
		 to be palindrome, each character should occur even number of 
		 times, except for one character can occur odd number of times */
		if(asci_list[s[i]] % 2 != 0)
		{
			count++;
			if(count > 1)
			{
				cout<<"permutations of given string cannot be palindromes"<<endl;
				return 0;
			}
		}
	}
	cout<<"permutations of the given string can be palindromes"<<endl;
}