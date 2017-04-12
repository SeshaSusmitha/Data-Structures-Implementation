#include <iostream>
#include <stack>
using namespace std;

class Queue_array
{
	private:
		stack<int> s1;
		stack<int> s2;

	public:
		/* Method to push elemnt to the stack */
		void enqueue(int val)
		{
			s1.push(val);
		}

		/* Method to pop top element from stack */
		int dequeue()
		{
			
			while (!s1.empty()) 
			{
		      	s2.push(s1.top());
		      	s1.pop();
	  		}
	   		/* Pop and store the top element from s2 */
	  		int ret = s2.top();
	   		s2.pop();
	   		
	   		/* Transfer all elements of s2 back to s1 */
	  		 while (!s2.empty())
	  		 {
	      		s1.push(s2.top());
	      		s2.pop();
	  		 }
	   		return ret;
		}

	
		/* Method to print elements of stack */
		void print()
		{
			cout<<"Elements of queue : "<<endl;
		   	while (!s1.empty()) 
		   	{
		      s2.push(s1.top());
		      s1.pop();
		  	}
		   while (!s2.empty())
		   {
		      cout<<s2.top()<<" ";
		      s1.push(s2.top());
		      s2.pop();
		   }
		   cout<<endl;
		}

};


int main()
{
	Queue_array qa;
	qa.enqueue(1);
	qa.enqueue(2);
	qa.enqueue(3);
	qa.enqueue(4);
	qa.print();
	qa.dequeue();
	qa.print();
}