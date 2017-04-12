/********************************************************************************
********************Program to implement three stacks usinga single array********
1st stack grows from left of the array, second stack from max-size/3 to the right
and 3rd array grows from right corner to the left
********************************************************************************/

#include <iostream>
using namespace std;

#define max_size 10
int count1 = 1, count2 = 2, count3 = 0;

class twoStack
{
	private:

		int A[max_size]; /* Maximum size of the array */
		int top1, top2, top3;

	public:
		twoStack()
		{
			top1 = -1;
			top2 = max_size;
			top3 = max_size/3;
		}

		void push1(int val) /* Pushes element into first stack */
		{
			if(top1 == max_size/3) /* Returns an error if stack is already full */
			{
				cout<<"stack 1 overflow"<<endl;
				return;
			}
			else 
			{
				A[++top1] = val;
				count1++;
			}
		}

		void push2(int val) /* Pushes element into second stack */
		{

			if(top2 == top3) /* Returns an error if stack is already full */
			{
				cout<<"stack 2 overflow"<<endl;
				return;
			}
			else
			{
				top2--;
				A[top2] = val;
				count2++;
			}
		}
		void push3(int val)
		{
			if(top3 == top2)
			{
				cout<<"stack 3 overflow"<<endl;
				return;
			}
			else
			{
				A[top3] = val;
				top3++;
				count3++;
			}
		}

		int pop1()	/* Pops element from first stack */
		{
			if(top1 == -1) /* Returns an error if stack is empty */
			{
				cout<<"Stack 1 underflow"<<endl;
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
				cout<<"Stack 2 underflow"<<endl;
				return -1;
			}
			else
			{
				int ele = A[top2];
				top2++;
				return ele;
			}
		}

		int pop3()
		{
			if(top3 == max_size/3)
			{
				cout<<"Stack 3 underflow"<<endl;
				return -1;

			}
			else
			{
				top3--;
				int ele = A[top3];
				
				return ele;
			}

		}


		void printStack1() /* Method to print elements of stack1 */
		{
			if(top1 == -1) /* Returns an error if stack is empty */
			{
				cout<<"Stack 1 underflow...No elements to display"<<endl;
				return ;
			}
			else
			{	
				for(int i = top1; i >=0 ; i--)
				{
					if(count1 >= 1)
						cout<<A[i]<<" ";
					count1--;
				}
				cout<<endl;
			}
		}
		void printStack2() /* Method to print elements of stack2 */
		{
			if(top2 == max_size) /* Returns an error if stack is empty */
			{
				cout<<"Stack 2 underflow....No elements to display"<<endl;
				return ;
			}
			else
			{	
				for(int i = top2; i < max_size ; i++)
				{
					if(count2 >= 1)
						cout<<A[i]<<" ";
					count2--;
				}
				cout<<endl;
			}
		}
		void printStack3() /* Method to print elements of stack3 */
		{
			if(top3 == max_size/3) /* Returns an error if stack is empty */
			{
				cout<<"Stack 3 underflow....No elements to display"<<endl;
				return ;
			}
			else
			{	
				for(int i = max_size/3; i < top2 ; i++)
				{
					if(count3 >= 1)
						cout<<A[i]<<" ";
					count3--;
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
	ts.printStack3();
	ts.push1(1);
	ts.push2(2);
	ts.push1(3);
	ts.push2(4);
	ts.push1(5);
	ts.push2(6);
	ts.push3(7);
	ts.push3(8);
	ts.push3(9);
	cout<<"Elements of stack 1 : "<<endl;
	ts.printStack1();
	cout<<"Elements of stack 2 : "<<endl;
	ts.printStack2();
	cout<<"Elements of stack 3 : "<<endl;
	ts.printStack3();
	cout<<ts.pop1()<<endl;
	cout<<ts.pop2()<<endl;
	cout<<ts.pop3()<<endl;
}