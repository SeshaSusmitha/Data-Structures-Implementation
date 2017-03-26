#include <iostream>
using namespace std;

class hash_class
{
	private:
		int table_size;
	
	public:
		int Hash_fun(string key);
		hash_class()
		{
			table_size = 100;
		}

};


int hash_class :: Hash_fun(string key)
{
	int hash_sum = 0;
	for(int i = 0; i < key.length(); i++)
	{
		hash_sum = hash_sum+(int)key[i];
	}
	cout<<"hash_sum = "<<hash_sum<<endl;
	return hash_sum % table_size;
}


int main()
{
	hash_class hashObj;
	int index;
	index = hashObj.Hash_fun("susmitanaren");
	cout<<"Index = "<<index<<endl;
}