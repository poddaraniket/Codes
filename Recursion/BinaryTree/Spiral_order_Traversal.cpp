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

void spiral(Node *x)
{
    int level=0;
    deque<Node *> q;
    q.push_back(x);
    while(!q.empty())
     {
        int size=q.size(); 
        if(level%2==0)
         { 
             while(size--)
              {
                Node *temp=q.back();
                q.pop_back();
                cout<<temp->data<<" ";
                if(temp->right!=NULL)
                 q.push_front(temp->right);
                if(temp->left!=NULL)
                 q.push_front(temp->left);  
              }
             level++; 
         }
        else 
         {
             int size=q.size(); 
             while(size--)
              {
                Node *temp=q.front();
                q.pop_front();
                cout<<temp->data<<" ";
                if(temp->left!=NULL)
                 q.push_back(temp->left);
                if(temp->right!=NULL)
                 q.push_back(temp->right);
              }
             level++; 
         }
     }
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
	spiral(x);
	return 0;
}
