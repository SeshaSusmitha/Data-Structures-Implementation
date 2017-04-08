#include <iostream>
#include <map>
using namespace std;

int main()
{
	/* Declaring a map, <int, string> refers to key, value pair */
	map<int, string> my_map;

	/*Initializing key 1 to the value "string[1]" */
	my_map[1] = "string[1]";

	/* Inserting key. value pairs into map using insert method */
	my_map.insert(pair<int, string> (2, "string[2]"));
	my_map.insert(pair<int, string> (3, "string[3]"));
	my_map.insert(pair<int, string> (4, "string[4]"));
	my_map.insert(pair<int, string> (5, "string[5]"));

	/* Checking if the map is empty using empty() method.
	Returns true / false */
	cout << my_map.empty()<<endl;
	
	/* Traversing through the map using iterator */
	for(map<int, string> :: iterator it = my_map.begin(); it != my_map.end(); it++)
	{
		cout<< it->first<< " -> " << it->second << endl;
	}

	/* Finding a value in a map using find() method */
	map <int, string> :: iterator it = my_map.find(3);
	cout <<"Key found = "<< it->second << endl;

	/* Erasing a pair form the map using erase() method */
	my_map.erase(it);
	cout <<"After erase = "<< it->second << endl;

	for(map<int, string> :: iterator it = my_map.begin(); it != my_map.end(); it++)
	{
		cout<< it->first<< " -> " << it->second << endl;
	}

	/* Clearing the map using clear() method */
	my_map.clear();

	/* Checking if the map is empty. Returns true as the map is now empty. */
	cout << my_map.empty()<<endl;
}
