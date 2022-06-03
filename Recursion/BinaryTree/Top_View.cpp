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
   if(mp.find(side)==mp.end() || level<mp[side].second) 
    // here mp[side].second intitailly 0 so to get least level sides you need to store the first level of that distance 
    //so that you can compare with that if you don't you will be comparing with 0 all the time so you won't get any min levels
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
