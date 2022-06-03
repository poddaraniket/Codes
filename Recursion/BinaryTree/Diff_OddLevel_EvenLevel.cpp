#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node *left, *right, *next;

	// constructor
	Node(int data)
	{
		this->data = data;
		this->left = this->right = this->next = nullptr;
	}
};

void findDiff(Node *root)
{
    int odd=0,even=0;
    queue<Node*>q;
    queue<int> level;
    q.push(root);
    level.push(1);
    while(!q.empty())
    {
        Node *temp=q.front();
        int lev=level.front();
        q.pop();
        level.pop();
        if(lev%2==0)
         even+=temp->data;
        else
         odd+=temp->data;
        if(temp->left!=NULL)
         {
           q.push(temp->left);
           level.push(lev+1);
         }
        if(temp->right!=NULL)
         {
             q.push(temp->right);
             level.push(lev+1);
         }
    }
   cout<<odd-even<<endl;    
}

int main() {
	// your code goes here
	Node* root = nullptr;
    /* Construct below tree
			  1
			/   \
		   /     \
		  2       3
		 /      /  \
		/      /    \
	   4      5      6
			 / \
			/   \
		   7     8
    */

    root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->right->left = new Node(5);
	root->right->right = new Node(6);
	root->right->left->left = new Node(7);
	root->right->left->right = new Node(8);

    findDiff(root);

    return 0;
}
