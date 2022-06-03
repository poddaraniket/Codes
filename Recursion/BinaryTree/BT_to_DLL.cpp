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

void printDLL(Node* &head)
{
    //cout<<"*"<<endl;
    Node *temp=head;
    //cout<<temp->data<<" ";
    while(temp)
     {
        cout<<temp->data<<" ";
        temp=temp->right;
     }
}

void convert(Node *root,Node* &head)
{
    if(root==NULL)
     return;
    static Node* prev=NULL;
    convert(root->left,head);
    if(prev==NULL)
     head=root;
    else
     {
        root->left=prev;
        prev->right=root;
     }
    prev=root;
    //cout<<prev->data<<" ";
    convert(root->right,head);
}

int main() {
	// your code goes here
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);

    Node *head=NULL;
	convert(root,head);
	//cout<<"*";
	printDLL(head);
	return 0;
}
