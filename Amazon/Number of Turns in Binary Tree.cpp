#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node *left, *right;

	Node(int data)
	{
	this->data = data;
	this->left = this->right =NULL;
	}
};


// no. of turns to reac each node from root 

bool Turnings(Node *root,int num,bool turn,int &count)
{
    if(root==NULL)
     return false;
    if(root->data==num)
     return true;
    if(turn==true)
     {
        if(Turnings(root->left,num,turn,count))
         return true;
        if(Turnings(root->right,num,!turn,count)) 
         {
            count++;
            return true;
         }
     }
    else
     {
        if(Turnings(root->right,num,turn,count))
        {
          return true;
        }
        if(Turnings(root->left,num,!turn,count)) 
         {
            count++;    
            return true;
         } 
     }
    return false; 
}


// if one of the two node is LCA then no. of turn will be counted from that node not root
bool LCA(Node* root,int n1,int n2,int &lca)
{
    if(root==NULL)
     return false;
    if(root->data==n1 || root->data==n2)
     {
        lca=root->data; 
        return true;
     }
    bool left=LCA(root->left,n1,n2,lca);
    bool right=LCA(root->right,n1,n2,lca);
    if(left && right)
     {
         lca=root->data;
         return true;
     }
    return left || right; 
}


int NumOfTurns(Node *root,int n1,int n2)
{
    int count=0,c=0,c1=0;
    int lca=-1;
    if(!LCA(root,n1,n2,lca))
     return 0; 
    if(Turnings(root->left,n1,true,count) || Turnings(root->right,n1,false,count))
     {
      c=count;
      //cout<<c<<endl;
      count=0;
     }
    if(Turnings(root->left,n2,true,count) || Turnings(root->right,n2,false,count))
    {
     c1=count;
     //cout<<c1<<endl;
    }
    if(lca==n1 || lca==n2)
     {
        return abs(c-c1);
     }
    else
    {
     return (c+c1)+1;
    }
}

// void preorder(Node *root)
// {
//     if(root==NULL)
//      return;
//     cout<<root->data<<" ";
//     preorder(root->left);
//     preorder(root->right);
// }

int main() {
	// your code goes here
	Node *root=NULL;
	root = new Node(1); 
    root->left = new Node(2); 
    root->right = new Node(3); 
    root->left->left = new Node(4); 
    root->left->right = new Node(5); 
    root->right->left = new Node(6); 
    root->right->right = new Node(7); 
    root->left->left->left = new Node(8); 
    root->right->left->left = new Node(9); 
    root->right->left->right = new Node(10); 
    int turn=NumOfTurns(root,2,8);
    if(turn)
     cout<<turn<<endl;
    else
     cout<<"Not Possible"<<endl;
	return 0;
}
