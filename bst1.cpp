/*BINARY SEARCH TREE OPERATIONS

1. INSERTION 2.DELETION 3.TRAVERSING 4.SEARCHING*/



#include <iostream>

using namespace std;

struct BST

{

int data;

struct BST*lchild,*rchild;

}*root=NULL,*ptr,*ptr1,*n;

int item,k=0,s;

void insert()

{

cout<<"Enter Element To Be Insert";

cin>>item;

ptr=root;

if(ptr==NULL)

{

n=(struct BST*)malloc(sizeof(struct BST));

n->data=item;n->lchild=n->rchild=NULL;

cout<<"Element Is Successfully Inserted";

root=n;return;

}

while(ptr!=NULL)

{

if(item<ptr->data)

{

  ptr1=ptr;

  ptr=ptr->lchild;

}

else if(item>ptr->data)

{

  ptr1=ptr;

  ptr=ptr->rchild;

}

else

{

  if(item==ptr->data)

  {

    cout<<"Item Already Exists";

    return;

  }

}

}

if(ptr==NULL)

{

n=(struct BST*)malloc(sizeof(struct BST));

n->data=item;n->lchild=n->rchild=NULL;

if(ptr1->data<item)

ptr1->rchild=n;

else

ptr1->lchild=n;

}

}

void case1()

{

if(ptr1->lchild==ptr)

ptr1->lchild=NULL;

else

ptr1->rchild=NULL;

cout<<“Element Is Successfully Deleted”;

ptr=NULL;

}

void case2()

{

struct BST*ptr2,*y;

int x=0;

ptr2=ptr->rchild;

if(ptr2->lchild==NULL&&ptr2->rchild==NULL)

{

ptr1->lchild=ptr2;

ptr1->lchild->lchild=ptr->lchild;

}

else if(ptr2->lchild==NULL&&ptr2->rchild!=NULL)

{

ptr1->rchild=ptr2;

ptr1->rchild->lchild=ptr->lchild;

ptr=NULL;

free(ptr);

}

else

{

while(ptr2->lchild!=NULL)

  ptr2=ptr2->lchild;

if(ptr2->rchild!=NULL)

{x=1;y=ptr2->rchild;}

  ptr1->lchild=ptr2;

  ptr2->lchild=ptr->lchild;

  ptr2->rchild=ptr->rchild;

  if(x==1)

  ptr2->rchild->lchild=y;

else

  ptr2->rchild->lchild=NULL;

  ptr=NULL;

  free(ptr);

}

}

void case3()

{

if(ptr1->lchild==ptr)

{

  if(ptr->lchild==NULL)

    ptr1->lchild=ptr->rchild;

  else

    ptr1->lchild=ptr->lchild;

}

else

{

if(ptr1->rchild==ptr)

{

  if(ptr->lchild==NULL)

    ptr1->rchild=ptr->rchild;

  else

    ptr1->rchild=ptr->lchild;

}  

}

cout<<“Element Is Successfully Deleted”;

ptr=NULL;

}

void delet(int item)

{

int c=0;

struct BST*pt;

ptr=root;

if(ptr==NULL)

{

  cout<<“Tree Is Empty”;

  return;

}

if(ptr->data==item)

{

  cout<<item<<“Is A Root Node Deletion Is Not Possible”;

  return;

}

if(ptr->data==item&&ptr->lchild==NULL&&ptr->rchild==NULL)

{

  root=NULL;

  cout<<“Item”<<item<<“Is Successfully Deleted”;

  return;

}

while((ptr!=NULL)&&(c==0))

{

  if(item<ptr->data)

  {

    ptr1=ptr;

    ptr=ptr->lchild;

  }

  else if(item>ptr->data)

  {

    ptr1=ptr;

    ptr=ptr->rchild;

  }

  else

    c=1;

}

if(c==0)

{

  cout<<“Item Does Not Exist..,Deletion Is Not Possible”;

  return;

}

if(ptr->lchild==NULL&&ptr->rchild==NULL)

case1();

  else if(ptr->lchild!=NULL&&ptr->rchild!=NULL)

case2();

  else

case3();

}

void traverse(struct BST*ptr)

{

if(ptr!=NULL)

{

  traverse(ptr->lchild);

  cout<<ptr->data<<“ ”;

  traverse(ptr->rchild);

}

}

int searching(struct BST*p,int key)

{

if(p!=NULL)

{

  if(p->data==key)

  k=1;

  else

  {

    searching(p->lchild,key);

    searching(p->rchild,key);

  }

}

return k;

}

main()

{

int ch;

clrscr();

while(1)

{

  cout<<“\nBINARY SEARCH TREE OPERATIONS\n1.INSERTION\n2.DELETION\n”;

  cout<<“3.TRAVRSE\n4.SEARCHING\n5.EXIT”;cout<<“\nEnter Your Choice”;

  cin>>ch;

  switch(ch)

  {

    case 1:insert();break;

    case 2:cout<<“Which Item You Want To Delete”;cin>>item;

      delet(item);break;

    case 3:if(root==NULL){cout<<“Treee Is Empty”;break;}

      cout<<“Tree Elements Are”;traverse(root);break;

    case 4:if(root==NULL){cout<<“Tree Is Empty”;break;}

      s=k=0;cout<<“Which Item You Want To Search”;

      cin>>item;

      s=searching(root,item);

      if(s==1)

        cout<<“Item”<<item<<“Is Found”;

      else

        cout<<“Item”<<item<<“Is Not Found”;

      break;

    case 5:exit(0);

    default:cout<<“Invalid Choice”;

  }

}

}


