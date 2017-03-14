#include <iostream>
#include <stack>
using namespace std;

int main()
{
	//string str = "";
	string str = "{(){}}";
	stack <char> S;
	cout<<"string length: "<<str.length()<<endl;
	int str_len = str.length();
	if((str_len) == 0)
	{
		cout<<"NULL string\n";
		return 0;
	}
	else
	{	

		for(int i = 0; i < str_len ; i++ )
		{
			if(str[i] == '{' || str[i] == '(' || str[i] == '[')
				S.push(str[i]);
			else if((str[i] == '}' && S.top() != '{') || (str[i] == ')' && S.top() != '(') 
					 || (str[i] == ']' && S.top() != '[') || (S.empty()))
			{
					cout<<"not balanced"<<endl;	
					return false;
			}
			else
				S.pop();
		}
		cout<<"Balanced"<<endl;
	}
}