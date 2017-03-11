#include <iostream>
using namespace std;

/* Structure of a new node */

struct node
{
	int data;
	struct node *next;
}*front,*rear; /* front - pointer to start of queue rear - pointer to the end of queue */

/* Queue class */

class queue_ll
{

	public:
		void enqueue(int);
		void dequeue();
		void display();

		/* Initializing top of stack to NULL */

		queue_ll()
		{
			front = NULL;
			rear = NULL;
		}
};

int main()
{
	queue_ll ql;
	int choice,item;
	while(1)
	{
		cout<<"\nOperations on stack:"<<endl;
		cout<<"1. Enqueue \n2. Dequeue \n3. Display \n4. Exit \n";

		cout<<"\nEnter your choice: "<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1:
					cout<<"\nEnter element to push: ";
					cin>>item;
					 ql.enqueue(item);
					break;
			case 2:
					ql.dequeue();
					break;
			case 3:
					ql.display();
					break;
			case 4:
					exit(1);
					break;
			default:
					cout<<"\nwrong choice\n";

		}
	}

	return 0;


}

/* Inserting element into stack */

void queue_ll :: enqueue(int item)
{
	//cout<<"In push method"<<endl;
	struct node *temp;
	temp = new(struct node);
	temp->data = item;
	temp->next = NULL;
	if(front == NULL)
	{
		front = temp;
	}

	else
	{
		rear->next = temp;
	}
	rear = temp;
}

/* Popping(deleting) the top element of the stack */

void queue_ll :: dequeue()
{
	struct node *temp;
	if(front == NULL)
	{
		cout<<"Queue empty"<<endl;
	}
	else
	{
		temp = front;
		front = front->next;
		//free(temp);
		delete temp;
		cout<<"Front element popped"<<endl;
	}
	
}


/* Traversing all elements of stack and displaying */

void queue_ll :: display()
{
	struct node *temp;
	temp = front;
	if(front == NULL)
	{
		cout<<"\nQueue empty, no elements to display\n"<<endl;
	}
	else
	{	
		cout<<"\nElements in queue are:"<<endl;
		while(temp != NULL)
		{
			cout<<temp->data<<endl;
			temp = temp->next;
		}
	}
}