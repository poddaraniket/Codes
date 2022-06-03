#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left,*right;
    Node(int data)
     {
        this->data=data;
        this->left=NULL;
        this->right=NULL;
     }
};

void deleteBT(Node* &x)
{
    if(x==NULL)
     return;
    deleteBT(x->left);
    deleteBT(x->right);
    delete x;
    x=NULL;
}

int main() {
	// your code goes here
	Node *x=NULL;
	x=new Node(15);
	x->left=new Node(10);
	x->right=new Node(20);
	x->left->left=new Node(8);
 	x->left->right=new Node(12);
	x->right->left=new Node(16);
	x->right->right=new Node(25);
	deleteBT(x);
	if(x==NULL)
	 cout<<"YES"<<endl;
	else
	 cout<<"NO"<<endl;
	return 0;
}
