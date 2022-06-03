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

void height(Node* x,int ht,int &ans)
{
    if (x==NULL)
    {
	  ans=max(ans,ht);
	  return;
    }
	// if both trees are non-empty and value of their root node matches,
	// recur for their left and right sub-tree
    height(x->left,ht+1,ans);
    height(x->right,ht+1,ans);
}

int main() {
	// your code goes here
	Node *x=NULL;
	x=new Node(15);
	x->left=new Node(10);
	x->right=new Node(20);
	x->left->left=new Node(8);
 	x->left->right=new Node(12);
// 	x->right->left=new Node(16);
// 	x->right->right=new Node(25);
	
	int ans;
	height(x,0,ans);
	cout<<ans<<endl;
	return 0;
}
