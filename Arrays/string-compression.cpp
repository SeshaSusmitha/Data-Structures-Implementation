#include <iostream>
using namespace std;

int main(){
	string s = "AAAABBBCC";
	string new_str = "";
	int len = s.length(), i = 1, count = 1;
	if(len == 0){
		cout << "zero length" << endl;
		return 0;
	}
	if(len == 1){
		s = s + '1';
		cout << s << endl;
		return 0;
	}
	while(i < len){
		if(s[i] == s[i-1]){
			count += 1;

		}
		else{
			new_str = new_str + s[i-1] + to_string(count);
			count = 1;
		}
		i += 1;
	}
	
	new_str = new_str + s[i-1] + to_string(count);
	cout << new_str << endl;
}