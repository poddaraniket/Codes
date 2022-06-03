#include <bits/stdc++.h>
using namespace std;

int x1_lev=-1,x2_lev=-1;

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

void Cousins(Node* x,int x1,int x2,int level)
{
   if(x==NULL)
    return;
   if(x->data==x1)
     x1_lev=level;
   if(x->data==x2)
    x2_lev=level;
   Cousins(x->left,x1,x2,level+1);
   Cousins(x->right,x1,x2,level+1);
}

int main() {
	// your code goes here
	Node *x=NULL;
	x = new Node(1);
	x->left = new Node(2);
	x->right = new Node(3);
	x->left->right = new Node(4);
	x->right->left = new Node(5);
	x->right->right = new Node(6);
	x->right->left->left = new Node(7);
	x->right->left->right = new Node(8);
	
	//int ans;
    Cousins(x,4,6,0);
	//cout<<ans<<endl;
	if(x1_lev==x2_lev && x1_lev!=-1)
	 cout<<"true"<<endl;
	else
	 cout<<"false"<<endl;
	return 0;
}
