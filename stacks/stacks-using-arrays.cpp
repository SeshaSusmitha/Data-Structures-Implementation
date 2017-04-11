#include <iostream>
using namespace std;

#define max_size 5

class Stack_array
{
	private:

		int A[max_size];
		int top;

	public:

		/* Constructor */
		Stack_array()
		{
			top = -1;
		}

		/* Method to push elemnt to the stack */
		void push(int val)
		{
			if(top == max_size - 1) /* Returns an error if stack is already full */
			{
				cout<<"stack overflow"<<endl;
				return;
			}
			else
			{
				A[++top] = val;
			}
		}

		/* Method to pop top element from stack */

		void pop()
		{
			if(top == -1) /* Returns an error if stack is empty */
			{
				cout<<"Stack underflow"<<endl;
				return;
			}
			else
			{
				cout<<A[top];
				top--;
			}
			cout<<endl;
		}

		/* Method that returns top element of stack */
		void top_ele()
		{
			if(top == -1) /* Returns an error if stack is empty */
			{
				cout<<"Stack underflow"<<endl;
				return;
			}
			cout<<A[top]<<endl;

		}

		/* Method to print elements of stack */
		void print()
		{
			if(top == -1)
			{
				cout<<"Stack underflow"<<endl;
				return;
			}
			for(int i = 0; i <= top; i++)
			{
				cout<<A[i]<<" ";
			}
			cout<<endl;
		}

};


int main()
{
	Stack_array sa;
	sa.top_ele();
	sa.pop();	
	sa.push(1);
	sa.push(2);
	sa.push(3);
	sa.push(4);
	sa.push(5);
	sa.push(6);
	sa.top_ele();
	sa.print();
	sa.pop();
	sa.print();
}