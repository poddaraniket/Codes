#include <bits/stdc++.h>
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

Node* insert(struct Node* node, int key){
	if (node == NULL) return new Node(key);
	if (key < node->data)
		node->left = insert(node->left, key);
	else if (key > node->data)
		node->right = insert(node->right, key);
	return node;
}

void preOrder(Node* node)
{
	if (node == NULL)return;
	printf("%d ", node->data);
	preOrder(node->left);
	preOrder(node->right);
}

int height(struct Node* node) 
{
   if (node==NULL) return 0;
   else
   {
       int lDepth = height(node->left);
       int rDepth = height(node->right);
       if (lDepth > rDepth) return(lDepth+1);
       else return(rDepth+1);
   }
} 

Node* buildBalancedTree(Node* root);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        struct Node *root = NULL;
        int n, temp;
        cin>>n;
        while(n--)
        {
            cin>>temp;
            root = insert(root, temp);
        }
        // cout<<height(root)<<endl;
        root = buildBalancedTree(root);
        cout<<height(root)<<endl;
    }
	return 0;
}
// } Driver Code Ends


/*Structure of the Node of the BST is as
struct Node
{
	int data;
	Node* left, *right;
};
*/

void inorder(Node *root,vector<int> &v)   //it helps to insert the values in vector in ascending order
{
    if(root==NULL)
     return;
    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);
    //return (v,0,v.size()-1);
}

Node *BST(vector<int> v,int start,int end)  // through that vector print the Balanced Tree 
{
    if(start>end)
     return NULL;
    int mid=(end+start)/2; 
    Node *new_node=new Node(v[mid]);
    new_node->left=BST(v,start,mid-1);
    new_node->right=BST(v,mid+1,end);
    return new_node;
}

// Your are required to complete this function
// function should return root of the modified BST
Node* buildBalancedTree(Node* root)
{
	// Code here
	vector<int> v;
	inorder(root,v);
	return BST(v,0,v.size()-1);
}
