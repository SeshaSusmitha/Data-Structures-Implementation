/* Program to implement two stacks usinga single array */

#include <iostream>
using namespace std;


#define max_size 5

class twoStack
{
	private:

		int A[max_size];
		int top1, top2;

	public:
		twoStack()
		{
			top1 = -1;
			top2 = max_size;
		}

		void push1(int val) /* Pushes element into first stack */
		{
			if(top1 == top2 - 1) /* Returns an error if stack is already full */
			{
				cout<<"stack overflow"<<endl;
				return;
			}
			else
			{
				A[++top1] = val;
			}
		}

		void push2(int val) /* Pushes element into second stack */
		{

			if(top1 == top2 - 1) /* Returns an error if stack is already full */
			{
				cout<<"stack overflow"<<endl;
				return;
			}
			else
			{
				top2--;
				A[top2] = val;
			}
		}

		int pop1()	/* Pops element from first stack */
		{
			if(top1 == -1) /* Returns an error if stack is empty */
			{
				cout<<"Stack underflow"<<endl;
				return -1;
			}
			else
			{
				int ele = A[top1];
				top1--;
				return ele;
			}
		}
		int pop2()	/* Pops element from second stack */
		{
			if(top2 == max_size) /* Returns an error if stack is empty */
			{
				cout<<"Stack underflow"<<endl;
				return -1;
			}
			else
			{
				int ele = A[top2];
				top2++;
				return ele;
			}
		}
		void printStack1() /* Method to print elements of stack1 */
		{
			if(top1 == -1) /* Returns an error if stack is empty */
			{
				cout<<"Stack1 underflow...No elements to display"<<endl;
				return ;
			}
			else
			{	
				for(int i = top1; i >=0 ; i--)
				{
					cout<<A[i]<<" ";
				}
				cout<<endl;
			}
		}
		void printStack2() /* Method to print elements of stack2 */
		{
			if(top2 == max_size) /* Returns an error if stack is empty */
			{
				cout<<"Stack2 underflow....No elements to display"<<endl;
				return ;
			}
			else
			{	
				for(int i = top2; i < max_size ; i++)
				{
					cout<<A[i]<<" ";
				}
				cout<<endl;
			}
		}
};



int main()
{
	twoStack ts;
	ts.printStack1();
	ts.printStack2();
	ts.push1(1);
	ts.push2(2);
	ts.push1(3);
	ts.push2(4);
	ts.push1(5);
	ts.push2(6);
	cout<<"Elements of stack 1 : "<<endl;
	ts.printStack1();
	cout<<"Elements of stack 2 : "<<endl;
	ts.printStack2();
	cout<<ts.pop1()<<endl;
	cout<<ts.pop2()<<endl;
}