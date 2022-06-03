#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};

Node *buildTree(int a[],int b[],int str,int end);
int preIndex=0;
void printPostOrder(Node *root){
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		preIndex=0;
		Node *root=NULL;
		int a[n],b[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
		for(int i=0;i<n;i++)
			cin>>b[i];
		root=buildTree(a,b,0,n-1);
		printPostOrder(root);
		cout<<endl;
	}
}// } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
int search(int in[],int start,int end,int x)
{
    for(int i=start;i<=end;i++)
     {
        if(in[i]==x)
         return i;
     }
    return -1; 
}

Node* buildTreehelper(int in[],int pre[],int preS,int preE,int inS,int inE)
{
    if(inS>inE)
     {
        return NULL; 
     }
    int rootdata=pre[preS]; //first node of the section of preorder taken 
    int rootIndex=search(in,inS,inE,rootdata); 
    int linS=inS;
    int linE=rootIndex-1;
    int rinS=rootIndex+1;
    int rinE=inE;
    int lpreS=preS+1;
    int lpreE=(linE-linS)+lpreS; //size of any subtree in inorder and preorder is same 
    int rpreS=lpreE+1;
    int rpreE=preE;
   
    Node *new_node=new Node(rootdata);
    new_node->left=buildTreehelper(in,pre,lpreS,lpreE,linS,linE);
    new_node->right=buildTreehelper(in,pre,rpreS,rpreE,rinS,rinE);
    return new_node;
}

Node* buildTree(int in[],int pre[], int inStrt, int inEnd)
{
//add code here.
  return buildTreehelper(in,pre,inStrt,inEnd,inStrt,inEnd);
}