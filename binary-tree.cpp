#include <iostream>
using namespace std;


struct node
{
	int data;
	struct node *left;
	struct node *right;
}*root;


class binarysearchtree
{
	public:
		void create_node(int);
		void insert_node(struct node *);
		void traversal();
		void print(struct node*);

		binarysearchtree()
		{
			root = NULL;
		}

};

int main()
{
	binarysearchtree bst;
	bst.create_node(4);
	//bst.create_node(2);
	// bst.create_node(6);
	// bst.create_node(1);
	// bst.create_node(3);
	// bst.create_node(5);
	// bst.create_node(8);
	bst.traversal();
}

void binarysearchtree :: create_node(int val)
{
	struct node *temp;
	temp = new(struct node);
	if(temp == NULL)
	{
		cout<<"Memory not allocated"<<endl;
		return ;
	}
	else
	{	
		temp->data = val;
		temp->left = NULL;
		temp->right = NULL;

		//return temp;
	}
	insert_node(temp);
}


void binarysearchtree :: insert_node(struct node *temp)
{
	struct node *temp_node;
	//temp = create_node(val);
	//temp_node = root;
	if(root == NULL)
	{
		root = temp;
		//root->left = NULL;
		//root->right = NULL;
	}

	else
	{
		if(temp->data < root->data)
			insert_node(root->left);
		else
			insert_node(root->right);
	}
}


void binarysearchtree :: traversal()
{
	print(root);
}

void binarysearchtree :: print(struct node *temp)
{
	if(temp != NULL)
	{
		print(temp->left);
		cout<<temp->data<<endl;
		cout<<temp->right;
	}
	else
	{
		cout<<"no ele to display"<<endl;
		return;
	}
}