#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <stack>
using namespace std;

/* Structure of node in the linked list */

struct node
{
	int data; //value of node
	struct node * next; //Link to next node
}*head;


class single_llist
{

	public:
		node * create_node(int);
		void insert_begin(int); // Inserts element at the beginning of linked list
		void display(); //Displays all elements or a message if the list is empty
		struct node* reverse(struct node*); // Reverses elements of linked list iteratively
		bool checkPalindrome(struct node*);
		struct node* deleteDuplicates(struct node*);

		single_llist()
		{
			head = NULL; //Initializing head pointer to NULL
		}
};


int main()
{
	single_llist sl;
	sl.display();

	sl.insert_begin(3);
	//sl.insert_begin(3);
	sl.insert_begin(2);
	//sl.insert_begin(1);
	sl.insert_begin(1);
	// sl.insert_begin(4);
	// sl.insert_begin(2);
	// sl.insert_begin(3);
	// sl.insert_begin(1);
	sl.display();
	sl.deleteDuplicates(head);
	sl.display();

	
}


/* Creates a new node in the linked list*/

node *single_llist :: create_node(int val)
{
	struct node *temp;
	temp = new (struct node);
	if(temp == NULL)
	{
		cout<<"Memory not allocated";
		return 0;
	}

	else
	{
		temp->data = val;
		temp->next = NULL;
		return temp;
	}

}

/* Inserts a new node in the linked list*/

void single_llist :: insert_begin(int val)
{
	struct node *temp, *temp1;
	temp = create_node(val);
	if(head == NULL)
	{
		head = temp;
		head->next = NULL;
	}
	else
	{
		temp1 = head;
		head = temp;
		head->next = temp1;
	}
	//cout<<"inserted ele "<<val<<endl;
}


/* Displays all elements from linked list */

void single_llist :: display()
{
	struct node *temp;
	temp = head;
	if(head == NULL)
	{
		cout<<"\nList is empty\n";
		return ;
	}
	cout<<"\nList of elements in the linked list :"<<endl;
	while(temp != NULL)
	{
		cout<<temp->data;
		cout<<"\n";
		temp = temp ->next;
	}
}




struct node* single_llist :: deleteDuplicates(struct node* head)
{
	struct node * current, *temp, *prev;
	prev = NULL;
	current = head;
	while(current != NULL)
	{
		cout<<"in while"<<endl;
		cout<<"hi"<<endl;
		if((current->data == current->next->data) || (current->data == prev->data))
		{
			cout<<"in if"<<endl;
			temp = current->next;
			current->next = temp->next;
			//delete temp;
			prev = current;
			current = current->next;
		}
		else
		{
			cout<<"in else"<<endl;
			prev = current;
			current = current->next;
		}
		cout<<"out"<<endl;
	}
	cout<<"out of while"<<endl;
	return head;
}
















