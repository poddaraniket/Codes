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

void LeftView(Node* x,int level,int &last_level)
{
   if(x==NULL)
    return;
   if(last_level<level)
    {
        cout<<x->data<<" ";
        last_level=level;
    }
   LeftView(x->left,level+1,last_level);
   LeftView(x->right,level+1,last_level);
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
	
	//int ans;
	int last_level=0;
	LeftView(x,1,last_level);
	//cout<<ans<<endl;
	return 0;
}
