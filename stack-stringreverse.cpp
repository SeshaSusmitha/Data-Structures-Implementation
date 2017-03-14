#include <iostream>
#include <stack>
using namespace std;

void string_reverse(char *c, int n)
{

	stack<char> s;
	for(int i = 0; i < n; i++)
	{
		s.push(c[i]);
	}

	for(int i = 0; i < n; i++)
	{
		c[i] = s.top();
		s.pop();  
	}

}

int main()
{
	char c[100];
	cout<<"Enter a string: ";
	cin>>c;
	//gets(c);
	string_reverse(c, strlen(c));
	cout<<c<<endl;
	//puts(c);
	//printf("%s", c);
}