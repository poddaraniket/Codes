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

void Leftview(Node* x)
{
    queue<Node*> q;
    q.push(x);
    while(!q.empty())
     {
        int size=q.size();
        int k=0;
        while(size--)
         {
             Node *temp=q.front();
             q.pop();
             if(k==0)
             {
              cout<<temp->data<<" ";
              k=1;
             }
             if(temp->left!=NULL)
              q.push(temp->left);
             if(temp->right!=NULL)
              q.push(temp->right);
         }
     }
    cout<<endl; 
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
	LeftView(x);
	//cout<<ans<<endl;
	return 0;
}
