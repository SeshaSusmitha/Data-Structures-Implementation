#include <iostream>
#include <vector>
using namespace std;
void insertion_sort(vector<int> nums, int length);
int main()
{
	vector <int> nums;
	nums.push_back(2);
	nums.push_back(7);
	nums.push_back(4);
	nums.push_back(1);
	nums.push_back(5);
	nums.push_back(3);
	int length = nums.size();
	cout<<"Array before insertion sort: "<<endl;
	for(int i = 0; i < length; i++)
		{
			cout<<nums[i]<<" ";
		}
		cout<<endl;
	insertion_sort(nums, length);
}

void insertion_sort(vector<int> nums, int length)
{
	int value, current_pos;

	for(int i = 1; i < length; i++)
	{
		value = nums[i];
		current_pos = i;

		while((current_pos > 0) && (nums[current_pos - 1] > value))
		{
			nums[current_pos] = nums[current_pos - 1];
			current_pos = current_pos - 1;
		}

		nums[current_pos] = value;
	}

	cout<<"Array after insertion sort: "<<endl;
	for(int i = 0; i < length; i++)
		{
			cout<<nums[i]<<" ";
		}
		cout<<endl;
}
