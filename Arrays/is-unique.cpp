/*********************************************************
Cracking the coding interview Q1.1 page no: 60
***********************************************************/

#include <iostream>
using namespace std;

bool isUnique(string s);
int main()
{
	string s = "susmita";
	cout<<isUnique(s)<<endl;;
}

// void isUnique(string s)
// {
// 	int asci_list[256] = {0};
// 	for(int i : s)
// 		asci_list[i]++;
// 	for(int i = 0; i < s.length(); i++)
// 	{
// 		if(asci_list[s[i]] != 1)
// 			cout<<s[i]<<endl;
// 	}
// }

bool isUnique(string s)
{
	int chckr = 0;
	for(int i = 0; i < s.length(); i++)
	{
		int val = s[i] - 'a';
		if((chckr & (1 << val)) < 0 )
		{
			return false;
		}
		chckr |= (1 << val);
	}
	return true;
}