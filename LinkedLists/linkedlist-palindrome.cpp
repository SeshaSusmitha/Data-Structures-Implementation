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

		single_llist()
		{
			head = NULL; //Initializing head pointer to NULL
		}
};


int main()
{
	single_llist sl;
	sl.display();

	sl.insert_begin(1);
	sl.insert_begin(3);
	sl.insert_begin(2);
	sl.insert_begin(4);
	sl.insert_begin(5);
	sl.insert_begin(4);
	sl.insert_begin(2);
	sl.insert_begin(3);
	sl.insert_begin(1);
	sl.display();
	sl.checkPalindrome(head);
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



struct node* single_llist :: reverse(struct node* head)
{
	struct node *current, *previous, *next;
	current = head;
	previous = NULL;

	if(head == NULL)
	{
		cout<<"no ele to reverse";
		return 0;
	}
	if(head->next == NULL)
	{
		return head;
	}
	else

	{
		cout<<"in rev out of while"<<endl;
		while(current != NULL)
		{
			next = current->next;
			current->next = previous;
			previous = current;
			current = next;
		}
		head = previous;
		//cout<<"head after reversal: "<<head->data<<endl;
		//cout<<"head next after reversal: "<<head->next->next->next->data<<endl;
		return head;
	}
}

bool single_llist :: checkPalindrome(struct node*)
{
	int count = 0;
	stack<int> mystack;
	struct node *temp,*temp1, *ptr;
	temp1 = head;
	ptr = head;
	int mid_value = 0;


	while(temp1 != NULL)
	{
		count++;
		temp1 = temp1->next;
	}
	mid_value = count/2;
	temp1 = head;
	count = 0;
	while(temp1 != NULL)
	{
		if(count == mid_value)
		{
			break;
		}
		temp1 = temp1->next;
		count++;;

	}
	while(temp1->next != NULL)
	{
		mystack.push(temp1->next->data);
		temp1 = temp1->next;
	}

	while((!mystack.empty()) && (ptr != temp1))
	{
		if(ptr->data == mystack.top())
		{
			mystack.pop();
			ptr = ptr->next;
		}
		else
		{
			return false;
		}
	}

	return true;

}















