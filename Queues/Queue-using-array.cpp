#include <iostream>
using namespace std;

#define max_size 5

class Queue_array
{
	private:

		int A[max_size];
		int rear, front;

	public:

		/* Constructor */
		Queue_array()
		{
			rear = -1;
			front = -1;
		}

		/* Method to push elemnt to the stack */
		void enqueue(int val)
		{
			if(rear == max_size - 1) /* Returns an error if stack is already full */
			{
				cout<<"Queue overflow"<<endl;
				return;
			}
			else
			{
				A[++rear] = val;
			}
		}

		/* Method to pop top element from stack */

		void dequeue()
		{
			if(front == -1 || front > rear) /* Returns an error if stack is empty */
			{
				cout<<"Queue underflow"<<endl;
				return;
			}
			else
			{
				cout<<A[front];
				front = front + 1;
			}
			cout<<endl;
		}

	
		/* Method to print elements of stack */
		void print()
		{
			if(rear == -1)
			{
				cout<<"Queue underflow"<<endl;
				return;
			}
			for(int i = front+1; i <= rear; i++)
			{
				cout<<A[i]<<" ";
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
	qa.dequeue();
	qa.print();
}