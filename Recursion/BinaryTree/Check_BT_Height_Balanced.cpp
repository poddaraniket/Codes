#include <bits/stdc++.h>
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

int flag=0;

int height(Node* root)
{
    if(root==NULL)
     {
       return 0;
     }
    
    // if(root->left!=NULL || root->right!=NULL)
    //  sum++;
    
    int left_ht=height(root->left);
    int right_ht=height(root->right);
    
    if(abs(left_ht-right_ht)>1)
     flag=1;
    
    return max(left_ht,right_ht)+1;
}

int main() {
	// your code goes here
	Node* root =NULL;
	root = new Node(6);
	root->left = new Node(3);
	root->right = new Node(8);
	root->right->left = new Node(4);
	root->right->right = new Node(2);
	root->right->left->left = new Node(1);
	root->right->left->right = new Node(7);
	root->right->right->right = new Node(3);
	
	height(root);
	
	
	if(flag==1)
	 cout<<"UNBALANCED"<<endl;
	else
	 cout<<"BALANCED"<<endl;
	return 0;
}
