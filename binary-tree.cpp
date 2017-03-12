#include <iostream>
using namespace std;


struct bst_node
{
	int data;
	struct bst_node *left;
	struct bst_node *right;
}*root;


class binarysearchtree
{
	public:
		void insert(int);
		void traversal();
		void print(struct bst_node *);

		binarysearchtree()
		{
			root = NULL;
		}
		bst_node* insert_node(bst_node *, int);
};

int main()
{
	binarysearchtree bst;
	bst.insert_node(root,4);
	bst.insert_node(root, 2);
	bst.insert_node(root, 6);
	// bst.insert(1);
	// bst.insert(3);
	// bst.insert(5);
	// bst.insert(8);
	bst.traversal();
	
	
}

void binarysearchtree :: insert(int val)
{

	insert_node(root, val);
}

bst_node * insert_node( bst_node *node, int val)
{
	if(node == NULL)
	{
		node = new (struct bst_node);
		node->data = val;
		node->left = NULL;
		node->right = NULL;
		return node;
	} 

	else 
	{	
		if(val < node->data)
		{
			node->left = insert_node(node->left, val);
		}

		else if(val > node->data)
		{
			node->right = insert_node(node->right, val);
		}
		return node;
	}
}

void binarysearchtree :: traversal()
{
	print(root);
}

void binarysearchtree :: print(struct bst_node *temp)
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