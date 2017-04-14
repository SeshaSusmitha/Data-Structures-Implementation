/*********************************************************************
******************String Compression Implmenetation*******************
*******************Cracking The Coding Interview Q 1.6 ***************
*********************************************************************/

#include <iostream>
using namespace std;

int main()
{
	string str = "aabccccaaa";
	string new_str;

	char ch ;
	char ch1;

	int i = 0, count = 1, j = 1, total_count = 0, flag;
	int length = str.length();
	
	
	while(i < length)
	{
		ch = str[i];
		cout << "ch = " << ch << endl;
		count = 1;
		j = i + 1;
		while(j < length)
		{	
			if(str[j] == ch)
			{
				count++;
				flag = 1;
				j++;
			}
			else
			{
				flag = 0;
				ch1 = count + '0';
				new_str += ch;
				new_str += ch1;
				break;
			}
		}
		i = i + count;
	}
	if(flag == 1)
	{
		new_str += ch;
		new_str += ch1;
	}

	cout<<"Compressed String = "<<new_str<<endl;

}