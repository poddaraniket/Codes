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

bool CompleteBT(Node* x)
{
   int flag=0;    
   queue<Node*> q;
   q.push(x);
   while(!q.empty())
    {
        Node *temp=q.front();
        q.pop();
        if(flag==1 && (temp->left!=NULL || temp->right!=NULL))
          return false;
        if(temp->left==NULL && temp->right!=NULL)
         return false;
        if(temp->left!=NULL)
          q.push(temp->left);
        else
          flag=1;
        if(temp->right!=NULL)  
         q.push(temp->right);
        else
         flag=1;
    }
   return true;    
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
	
	cout<<CompleteBT(x)<<endl;
	return 0;
}
