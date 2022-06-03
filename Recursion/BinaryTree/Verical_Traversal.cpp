#include<bits/stdc++.h>
using namespace std;

multimap <int,int> mp;

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

void verticalSum(Node *root,int dist)
{
    if(root==NULL)
      return;
    mp.insert(pair<int, int>(dist,root->data));
    verticalSum(root->left,dist-1);
    verticalSum(root->right,dist+1);
}

int main() {
	// your code goes here
	Node* root =NULL;
    root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->right->left = new Node(5);
	root->right->right = new Node(6);
	root->right->left->left = new Node(7);
	root->right->left->right = new Node(8);
	
	verticalSum(root,0);
	
	int temp=0;
	
	for(auto it=mp.begin();it!=mp.end();it++)
	 {
	    if(temp!=it->first)
	     {
	         cout<<endl;
	         temp=it->first;
	     }
	    cout<<it->second<<" "; 
	 }
    return 0;
}
