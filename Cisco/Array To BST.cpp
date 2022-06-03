#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *right;
    Node *left;
    Node(int data)
    {
        this->data=data;
        this->right=NULL;
        this->left=NULL;
    }
};

Node* bst(int arr[],int l,int r)
{
    if(l>r)
     return NULL;
    int mid=(l+r)/2;
    Node *root=new Node(arr[mid]);
    root->left=bst(arr,l,mid-1);
    root->right=bst(arr,mid+1,r);
    return root;
}

void preorder(Node *root)
{
    if(root==NULL)
     return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++) 
	     cin>>arr[i];
	    Node *root=bst(arr,0,n-1);
	    preorder(root);
	    cout<<endl;
	}
	return 0;
}