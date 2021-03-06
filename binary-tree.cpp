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
		void inorder(struct bst_node *& temp);
		struct bst_node* delete_node(bst_node*&, int);

		binarysearchtree()
		{
			root = NULL;
		}
		void insert_node(bst_node *&, int);
		bst_node* findMin(bst_node *);
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
	cout<<"after display"<<endl;
	bst.delete_node(root, 8);
	cout<<"node deleted\n";
	cout<<"root val = "<<root->right->data<<endl;
	bst.inorder(root);
	
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
		//cout<<"data inserted =" << node << " - " <<node->data<<endl;
		
	} 

	else 
	{	
		if(val < node->data)
		{
			//cout << val << " is less than " << node->data << endl;
			insert_node(node->left, val);
		}
		else
		{
			//cout << val << " is greater than " << node->data << endl;
			insert_node(node->right, val);
		}
	}
}

void binarysearchtree :: traversal()
{
	print(root);
}

void binarysearchtree :: inorder(struct bst_node *& temp)
{
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

void binarysearchtree :: print(struct bst_node *& temp)
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

bst_node* binarysearchtree :: delete_node(bst_node*& node, int val)
{
	cout<<"in delete method"<<endl;

	// no elements in tree
	if(node == NULL) return node;

	if(val < node->data)
		node->left = delete_node(node->left, val);
	else if(val > node->data)
		node->right = delete_node(node->right, val);
	else
	{
		// case 1: No children
		if(node->left == NULL && node->right == NULL)
		{
			cout<<"no children further"<<endl;
			cout<<"node data: "<<node->data<<endl;
			delete node;
			node = NULL;
			cout<<"child deleted"<<endl;
			//return node;
		}

		//case 2: one child

		else if(node->left == NULL)
		{
			cout<<"one right child"<<endl;
			struct bst_node *ptr = node;
			node = node->right;
			delete ptr;
			return node;
		}
		else if(node->right == NULL)
		{
			cout<<"one left child"<<endl;
			struct bst_node *ptr = node;
			node = node->right;
			delete ptr;
			return node;
		}
		//case 3: 2 children
		else
		{
			cout<<"2child"<<endl;
			struct bst_node *temp = findMin(node->right);
			node->data = temp->data;
			node->right = delete_node(node->right, temp->data);
		}
	}

}

bst_node * binarysearchtree :: findMin(bst_node* root)
{
	if(root == NULL)
	{
		cout<<"empty\n";
		return 0;
	}
	bst_node *current = root;
	while(current->left != NULL)
	{
		current = current->left;
	}
	return current;

}