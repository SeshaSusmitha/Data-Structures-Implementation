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
	//cout<<"root ="<<root->data<<endl;
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

void binarysearchtree :: insert_node( bst_node *& temp, int val)
{

	//cout<<"root val = "<< root->data<<endl;
	if(temp == NULL)
	{
		temp = new (struct bst_node);
		temp->data = val;
		temp->left = NULL;
		temp->right = NULL;
		cout<<"data inserted =" << temp << " - " <<temp->data<<endl;
		//return temp;
		
	} 

	else 
	{	
		if(val < temp->data)
		{
			cout<<"\nless val"<<endl;
			 insert_node(temp->left, val);

			// if (temp->left != NULL)
   //      	{
   //     		     insert_node(temp->left, val);	
	  // 		 }
	  //   	else
	  //   	{
	  //               temp->left->data = val;
	  //               (temp->left)->left = NULL;
	  //               (temp->left)->right = NULL;
	  //               cout<<"Node Added To Left"<<endl;
	  //               return temp;
	  //        }
        	
		}

		else if(val > temp->data)
		{
			cout<<"\nbig val"<<endl;
			insert_node(temp->right, val);


			// if (temp->right != NULL)
	  //       {
	  //           insert_node(temp->right, val);
	  //       }
	  //       else
	  //       {
	  //           temp->right->data = val;
	  //           (temp->right)->left = NULL;
	  //           (temp->right)->right = NULL;
	  //           cout<<"Node Added To Right"<<endl;
	  //           return temp;
	  //       }	
		}
		//return temp;
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