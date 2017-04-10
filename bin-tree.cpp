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
		void print(struct bst_node *);
		void inorder(struct bst_node *temp);

		binarysearchtree()
		{
			root = NULL;
		}
		void insert_node(bst_node *, int);
};

int main()
{
	binarysearchtree bst;
	bst.insert_node(root, 4);
	bst.insert_node(root, 2);
	bst.insert_node(root, 6);
	bst.insert_node(root, 1);
	bst.insert_node(root, 3);
	bst.insert_node(root, 5);
	bst.insert_node(root, 8);
	
	bst.inorder(root);
	
}

void binarysearchtree :: insert(int val)
{
	insert_node(root, val);
}

void binarysearchtree :: insert_node( bst_node * node, int val)
{
	if(node == NULL)
	{
		node = new (struct bst_node);
		node->data = val;
		node->left = NULL;
		node->right = NULL;
		cout<<"data inserted =" << node << " - " <<node->data<<endl;
		//return node;
		
		
	} 

	else 
	{	
		if(val < node->data)
		{
			cout << val << " is less than " << node->data << endl;
			/*node->left =*/ insert_node(node->left, val);
		}
		else
		{
			cout << val << " is greater than " << node->data << endl;
			/*node->right =*/ insert_node(node->right, val);
		}
		//return node;
	}
}

void binarysearchtree :: traversal()
{
	print(root);
}

void binarysearchtree :: inorder(struct bst_node * temp)
{
	cout<<"Elements in BST: "<<endl;
	if(temp != NULL)
	{
		inorder(temp->left);

		cout << temp->data << " " <<endl;
		
		inorder(temp->right);
	}
	else
	{
		// cout<<"\nno ele to display"<<endl;
		return;
	}
}

void binarysearchtree :: print(struct bst_node * temp)
{
	cout<<"Elements in the BST: ";
	if(temp != NULL)
	{
		cout << temp->data << " " <<endl;
		print(temp->left);
		cout << temp->data << " " <<endl;
		
	}
	else
	{
		cout<<"\nno ele to display"<<endl;
		return;
	}
}