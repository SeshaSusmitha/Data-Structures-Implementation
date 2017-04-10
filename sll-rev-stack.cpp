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
		void insert_end(int); //Inserts element at the end of linked list
		void delete_val(int); //Deletes element if available from the linked list
		void search(int); //Searches the list for the given element
		void display(); //Displays all elements or a message if the list is empty
		//struct node* reverse(struct node*); // Reverses elements of linked list iteratively
		void reverse();
		single_llist()
		{
			head = NULL; //Initializing head pointer to NULL
		}
};


int main()
{
	single_llist sl;
	//sl.display();
	//sl.reverse(head);
	//sl.delete_val(2);
	sl.insert_begin(2);
	sl.insert_begin(4);
	sl.insert_begin(6);
	sl.insert_begin(8);
	//sl.display();
	//sl.insert_end(6);
	//sl.insert_end(8);
	sl.display();
	//head= sl.reverse(head);
	sl.reverse();
	//cout<<"head: "<<head->data<<endl;
	sl.display();
	//sl.search(6);
	//sl.search(10);
	//sl.delete_val(1);
	//sl.delete_val(6);
	//sl.display();
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
	cout<<"inserted ele "<<val<<endl;
}

void single_llist :: insert_end(int val)
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
		// head = temp;
		// head->next = temp1;
		while(temp1->next != NULL)
		{
			temp1 = temp1->next;
		}
		temp1->next = temp;

	}
	cout<<"inserted ele "<<val<<endl;
}


/* Deletes the given element from the linked list */

void single_llist :: delete_val(int val)

{
	struct node *temp, *temp1;
	temp = head;
	if(temp == NULL)
	{
		cout<<"\nList is empty\n";
		return;
	}

	else
	{
		while(temp->next != NULL)
		{
			if(temp->next ->data == val)
			{
				
				temp1 = temp->next;
				temp->next = temp1->next;
				free(temp1); //Frees the deleted value from memory
				return;
			}
			else
			{
				temp = temp->next;
			}
		}
		cout<<"\nval to be deleted is not available in the list"<<endl;
	}
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

void single_llist ::search(int val)
{

	struct node *temp;
	temp = head;
	while(temp->next != NULL)
	{
		if(temp->data == val)
		{
			cout<<"\nElement found "<<endl;
			return;
		}
		else
		{
			temp = temp ->next;
		}
	}
	cout<<"\nElement to be searched not available in the list"<<endl;
}

//struct node* single_llist :: reverse(struct node* head)
void single_llist :: reverse()
{
	if(head == NULL)
		return;
	stack <struct node *> S;
	cout<<"in reverse method"<<endl;
	struct node *current;
	current = head;
	while(current != NULL)
	{
		S.push(current);
		current = current->next;
	}
	current = S.top();
	head = current;
	S.pop();

	while(!S.empty())
	{
		current->next = S.top();
		S.pop();
		current = current->next;
	}
	//current = current->next;
	current->next = NULL;
	//return head;
}















