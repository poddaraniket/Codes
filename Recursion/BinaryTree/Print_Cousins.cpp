#include <bits/stdc++.h>
using namespace std;

int find_lev=-1;

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

void Cousins(Node* x,int x1)
{
   int flag=0;    
   queue<Node *> q;
   queue<int> level;
   q.push(x);
   level.push(0);
   while(!q.empty())
    {
       Node *temp=q.front();
       int lev=level.front();
       q.pop();
       level.pop();
       if(find_lev==lev)
        {
            cout<<temp->data<<" ";
        }
       else
        {
            if(temp->left!=NULL)
             {
                q.push(temp->left);
                level.push(lev+1);
                if(temp->left->data==x1)
                 find_lev=lev+1;
             }
            if(temp->right!=NULL)
             {
                q.push(temp->right);
                level.push(lev+1);
                if(temp->right->data==x1)
                 find_lev=lev+1;
             } 
        }
    }
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
    Cousins(x,2);
	//cout<<ans<<endl;
	return 0;
}
