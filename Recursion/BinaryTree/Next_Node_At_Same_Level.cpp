#include <bits/stdc++.h>
using namespace std;

map<int,pair<int,int>> mp;

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

Node* NextNode(Node* x,int val,int curr_lev,int &level)
{
   if(x==NULL)
    return NULL;
   if(x->data==val)
   {
    level=curr_lev;
    return NULL;
   }
   else if(level)
    {
        if(curr_lev==level)
          return x;
    }
   Node* left=NextNode(x->left,val,curr_lev+1,level);
   if(left)
    return left;
   return NextNode(x->right,val,curr_lev+1,level);
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
	int level=0;
    Node *temp=NextNode(x,4,0,level);
	//cout<<ans<<endl;
	if(temp)
	 cout<<temp->data<<endl;
	else
	 cout<<"NULL"<<endl;
	return 0;
}
