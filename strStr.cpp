#include <iostream>
using namespace std;

int main()
{
	//string haystick = "susmitasum";
	string haystick = "mississippi";
	string needle = "missip";
	//string needle = "s";
	int i = 0, j = 0, k;

	int len1 = haystick.length();
	int len2 = needle.length();
	char a = needle[0];
	cout<<len1<<endl;
	while(i < len1)
	{
		//cout<<"jus entered while"<<endl;
		if(haystick[i] == a)
		{
			//cout<<"found 1st char"<<endl;
			k = i;
			while(j < len2)
			{
				//cout<<"entered j while loop"<<endl;
				//cout<<haystick[i]<<endl;
				//stringcout<< needle[j]<<endl;
				if(haystick[i] == needle[j])
				{
					//cout<<"in if block"<<endl;
					j++;
					i++;
				}
				else
				{
					j = 0;
					break;
				}
			}
			if(j == len2)
			{
				cout<<"found"<<endl;
				cout<<"index = "<<k<<endl;
				break;
			}
			else
			{
				cout<<"not found"<<endl;
				//break;
			}
			i++;
		}
		else
		{
			i++;
			cout<<"else"<<endl;
		}
	}
}