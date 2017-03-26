/************************ Implementation of HashTable **********************/
/************************ March 2017 ***************************************/
/******************** Reference : Paul Programming **************************/

#include <iostream>
using namespace std;

class hash_class
{
	private:
		static const int table_size = 3;
		struct item
		{
			string name;
			string drink;
			item *next;
		};
		item* hashTable[table_size];
	
	public:
		int Hash_fun(string key);
		
		hash_class()
		{
			for(int i = 0; i < table_size; i++)
			{
				hashTable[i] = new item;
				hashTable[i]->name = "empty";
				hashTable[i]->drink = "empty";
				hashTable[i]->next = NULL;

			}
		}
		void AddItem(string name, string drink);
		int numberofItems(int index);
		void printTable();

};


int hash_class :: Hash_fun(string key)
{
	int hash_sum = 0;
	for(int i = 0; i < key.length(); i++)
	{
		hash_sum = hash_sum+(int)key[i];
	}
	return hash_sum % table_size;
}

void hash_class :: AddItem(string name, string drink)
{
	int index;
	index = Hash_fun(name);
	if(hashTable[index]->name == "empty")
	{
		hashTable[index]->name = name;
		hashTable[index]->drink = drink;	
	}
	else
	{
		item* ptr = hashTable[index];
		item* n = new item;
		n->name = name;
		n->drink = drink;
		n->next = NULL;
		while(ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		ptr->next = n;
	}
}

int hash_class :: numberofItems(int index)
{
	int count = 0;
	if(hashTable[index]->name == "empty")
		return count;
	else
	{
		count++;
		item* ptr = hashTable[index];
		while(ptr->next != NULL)
		{
			count++;
			ptr = ptr->next;
		}
	}
	return count;
}

void hash_class :: printTable()
{
	int number;
	for(int i = 0; i < table_size; i++)
	{
		number = numberofItems(i);
		cout<<"---------------------------\n";
		cout<<"index = "<<i<<endl;
		cout<<"name = "<<hashTable[i]->name<<endl;
		cout<<"hashTable[i]->drink = "<<hashTable[i]->drink<<endl;
		cout<<"number of items = "<<number<<endl;
		cout<<"---------------------------\n";
	}
}


int main()
{
	hash_class hashObj;
	hashObj.AddItem("name1", "Coke");
	hashObj.AddItem("name1", "Thumsup");
	hashObj.AddItem("name2", "Pepsi");
	hashObj.printTable();
	
}