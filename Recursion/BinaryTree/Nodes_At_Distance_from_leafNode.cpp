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


unordered_map<Node *,Node *> mp;   // it maintains the parent and child mapping 
queue<Node *> pq;				   // stores all leaf nodes

void leafNodeDistance(Node *root)
{
    queue<Node *> q;
    q.push(root);
    while(!q.empty())
    {
        Node *temp=q.front();
        q.pop();
        if(temp->left!=NULL)
         {
             q.push(temp->left);
             mp[temp->left]=temp;
         }
        if(temp->right!=NULL)
         {
             q.push(temp->right);
             mp[temp->right]=temp;
         }
        if(temp->left==NULL && temp->right==NULL)   
         pq.push(temp);
    }
    
}

int main() {
	// your code goes here
	Node* root = NULL;

	root = new Node(15);
	root->left = new Node(10);
	root->right = new Node(20);
	root->left->left = new Node(8);
	root->left->right = new Node(12);
	root->right->left = new Node(16);
	root->right->right = new Node(25);
	root->right->left->left = new Node(18);

	int dist = 1;
	leafNodeDistance(root);
	set<int> s;
	while(!pq.empty())
	 {
	    int temp_dist=dist;
	    Node *temp=pq.front();
	    pq.pop();
	    while(temp_dist>1)    // it iterates the map till we reach the distance away from leaf node 
	     {
	         Node *temp=mp[temp];
	         if(mp.find(temp)==mp.end())    // we check if the a parent exist as far as mentioned
	          break;
	         temp_dist--;
	     }
	    if(mp.find(temp)!=mp.end() && temp_dist==1)
	     s.insert(mp[temp]->data);
	 }
	for(auto it=s.begin();it!=s.end();it++)
	 cout<<*it<<" ";
	cout<<endl; 
	return 0;
}
