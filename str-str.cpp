#include <iostream>
using namespace std;

int main()
{
	//string haystick = "susmitasum";
	string haystack = "mississippi";
	string needle = "issip";
	//string needle = "s";
	int i = 0, j = 0, k;

	int len1 = haystack.length();
	int len2 = needle.length();
	char a = needle[0];
	int count = 0;
	cout<<len1<<endl;
	while(i < len1)
	{
		cout<<"i ="<<i<<endl;
		if(haystack[i] != a)
		{
			cout<<"in if"<<endl;
			i++;
		}
		else if(haystack[i] == a)
		{
			cout<<"else"<<endl;
			while(j < len2)
			{
				if(needle[j] == haystack[i])
				{
					cout<<"in 2 nd if"<<endl;
					j++;
					i++;
					count++;
				}
				else
				{
					j = 0;
					i++;
				}
			}
		}
		if(count == len2)
			cout<<"found"<<endl;
		else
			cout<<"not found"<<endl;
	}
}