#include <iostream>
using namespace std;

/* Structure of a new node */

struct node
{
	int data;
	struct node *next;
}*top; // *top is the pointer to the top of stack */

/* Stack class */

class stack_ll
{

	public:
		node *push(node*, int);
		node *pop(node*);
		void traverse(node*);

		/* Initializing top of stack to NULL */

		stack_ll()
		{
			top = NULL;
		}
};

int main()
{
	stack_ll sl;
	int choice,item;
	while(1)
	{
		cout<<"\nOperations on stack:"<<endl;
		cout<<"1. Push \n2. Pop \n3. Traverse \n4. Exit \n";

		cout<<"\nEnter your choice: "<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1:
					cout<<"\nEnter element to push: ";
					cin>>item;
					top = sl.push(top, item);
					break;
			case 2:
					top = sl.pop(top);
					break;
			case 3:
					sl.traverse(top);
					break;
			case 4:
					exit(1);
					break;
			default:
					cout<<"wrong choice";

		}
	}

	return 0;


}

/* Inserting element into stack */

node *stack_ll :: push(node *top, int item)
{
	//cout<<"In push method"<<endl;
	struct node *temp;
	temp = new(struct node);
	temp->data = item;
	temp->next = top;
	top = temp;
	cout<<"Element pushed"<<endl;
	return top;
}

/* Popping(deleting) the top element of the stack */

node *stack_ll :: pop(node *top)
{
	struct node *temp;
	if(top == NULL)
	{
		cout<<"Stack empty"<<endl;
	}
	else
	{
		temp = top;
		top = top->next;
		free(temp);
		cout<<"Top element popped"<<endl;
	}
	
	return top;
}


/* Traversing all elements of stack and displaying */

void stack_ll :: traverse(node *top)
{
	struct node *temp;
	temp = top;
	if(top == NULL)
	{
		cout<<"Stack empty, no elements to display"<<endl;
	}
	else
	{	
		cout<<"\nElements in stack are:"<<endl;
		while(temp != NULL)
		{
			cout<<temp->data<<endl;
			temp = temp->next;
		}
	}
}