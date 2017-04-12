/*********************************************************
Cracking the Coding Interview Q1.2 page no: 60
***********************************************************/


#include <iostream>
#include <algorithm>
using namespace std;

bool checkPermutation(string s1, string s2);
int main()
{
	string s1 = "susmita";
	string s2 = "iusmtas";
	bool result;
	result = checkPermutation(s1,s2);
	if(result)
		cout<<"s1 is permuatation of s2"<<endl;
	else
		cout<<"s1 is not permuatation of s2"<<endl;
}

bool checkPermutation(string s1, string s2)
{
	bool flag;
	int i;

	/* If string lengths are different, they are permuattion of each other */
	if(s1.length() != s2.length())
	{
		flag = false;
		return flag;
	}
	else
	{
		/* Inbuilt sorting algorithm from <algorithm> header used to sort given strings*/
		sort(s1.begin(), s1.end());
		sort(s2.begin(), s2.end());
		cout<<"s1 after sorting: "<< s1<<endl;
		cout<<"s2 after sorting: "<<s2<<endl;

		/* To compare characters of both strings */
		while(i < s1.length())
		{
			if(s1[i] == s2[i])
			{
				cout<<s1[i]<<"-----"<<s2[i]<<endl;
				flag = true;
				i++;
			}
			else
			{
				flag = false;
				return flag;
			}
		}
		
	}
	return flag;

}