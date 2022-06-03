#include <bits/stdc++.h>
using namespace std;

map<int,pair<int,int>> mp;

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

void BottomView(Node* x,int side,int level)
{
   if(x==NULL)
    return;
   if(level>=mp[side].second) // here initially mp[side].second = 0 so level has to be greater than that 
    {
     mp[side].first=x->data;
     mp[side].second=level;    
    }
   BottomView(x->left,side-1,level+1);
   BottomView(x->right,side+1,level+1);
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
	int last_level=0;
    BottomView(x,0,0);
	//cout<<ans<<endl;
	for(auto it=mp.begin();it!=mp.end();it++)
	 cout<<it->second.first<<" ";
	cout<<endl; 
	return 0;
}
