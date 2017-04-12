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

		/* Method to push element to the stack */
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
		int	 top_ele()
		{
			if(top == -1) /* Returns an error if stack is empty */
			{
				cout<<"Stack underflow"<<endl;
				return -1;
			}
			return A[top];

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

		/* Method to find the minimum elemnt of the stack */
		int findMin()
		{
			int min_ele = top_ele();
			if(top == -1)
			{
				cout<<"stack underflow...no elements to display"<<endl;
			}
			else
			{	

				for(int i = top-1; i >= 0; i--)
				{
					if(A[i] < min_ele)
					{
						min_ele = A[i];
					}
				}
				cout<<"Minimum element of the stack is "<<endl;
				return min_ele;
			}
		}


};


int main()
{
	Stack_array sa;
	sa.push(1);
	sa.push(2);
	sa.push(3);
	sa.push(4);
	sa.push(5);
	cout<<sa.findMin()<<endl;
	cout<<"Elements of the stack are "<<endl;
	sa.print();
}