#include <iostream>
using namespace std;
int print(int);
int main()
{
	int n;
	//cout<<"enter n:";
	cin>>n;
	int i=0;
	
	print(n);
	cout<<"int)";
	while(n>2)
	{
		cout<<")";
		n--;
	}
	cout<<endl;
}

int print(int n)
{
	static string msg = "min(int, ";
	if(n>2)
		print(n-1);
	cout<<msg;
	return 0;

}