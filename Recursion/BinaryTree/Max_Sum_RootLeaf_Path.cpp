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

vector<int> ans;
int maxi=0;

void maxsum(Node* &root,vector<int> v,int sum)
{
    if(root==NULL)
     {
        if(sum>maxi)
         {
             maxi=sum;
             ans.clear();
             for(int i=0;i<v.size();i++)
              ans.push_back(v[i]);
         }
        return; 
     }
     
    sum+=root->data;
    v.push_back(root->data); 
    
    maxsum(root->left,v,sum);
    maxsum(root->right,v,sum);
    
}

int main() {
	// your code goes here
	Node* root =NULL;
	root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(8);
	root->left->right = new Node(4);
	root->right->left = new Node(5);
	root->right->right = new Node(6);
	root->left->right->left = new Node(10);
	root->right->left->left = new Node(7);
	root->right->left->right = new Node(9);
	root->right->right->right = new Node(5);

	vector<int> v;
	
	maxsum(root,v,0);
	
	cout<<"MAX SUM "<<maxi<<endl;
	cout<<"MAX PATH IS:"<<endl;
	for(int i=0;i<ans.size();i++)
	 {
	     cout<<ans[i]<<" ";
	 }
	cout<<endl; 
	return 0;
}
