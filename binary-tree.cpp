#include <iostream>
using namespace std;


struct bst_node
{
	int data;
	bst_node *left;
	bst_node *right;
}*root;


class binarysearchtree
{
	public:
		void insert(int);
		void traversal();
		void print(struct bst_node *&);

		binarysearchtree()
		{
			root = NULL;
		}
		void insert_node(bst_node *&, int);
};

int main()
{
	binarysearchtree bst;
	bst.insert_node(root,4);
	bst.insert_node(root, 2);
	bst.insert_node(root, 6);
	bst.insert_node(root, 1);
	bst.insert_node(root, 3);
	bst.insert_node(root, 5);
	bst.insert_node(root, 8);
	
	bst.traversal();
	
}

void binarysearchtree :: insert(int val)
{
	insert_node(root, val);
}

void binarysearchtree :: insert_node( bst_node *& node, int val)
{
	if(node == NULL)
	{
		node = new (struct bst_node);
		node->data = val;
		node->left = NULL;
		node->right = NULL;
		cout<<"data inserted =" << node << " - " <<node->data<<endl;
		
	} 

	else 
	{	
		if(val < node->data)
		{
			cout<<"\nless val"<<endl;
			insert_node(node->left, val);
		}

		else if(val > node->data)
		{
			cout<<"\nbig val"<<endl;
			insert_node(node->right, val);
		}
	}
}

void binarysearchtree :: traversal()
{
	print(root);
}

void binarysearchtree :: print(struct bst_node *& temp)
{
	if(temp != NULL)
	{
		cout << temp->data << " " <<endl;
		print(temp->left);
		
	}
	else
	{
		cout<<"\nno ele to display"<<endl;
		return;
	}
}