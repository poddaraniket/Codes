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

Node *constructTree (int [], int );

void printInorder (Node* node)
{
	if (node == NULL)
		return;
	printInorder(node->left);
	printf("%d ", node->data);
	printInorder(node->right);
	

}

int main ()
{   
    int t,n;
   scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int post[n];
        for(int i=0;i<n;i++)
        scanf("%d",&post[i]);

    Node* root = constructTree(post, n);

	printInorder(root);
    printf("\n");
}
	return 0;
}
// } Driver Code Ends


/*struct Node
{
	int data;
	Node *left, *right;
};*/

int search(int pos[],int start,int end,int x)
{
    int i;
    for(i=start;i<=end;i++)
     {
        if(x<pos[i])
         break;
     }
    return i; 
}

Node *constructTreehelper(int pos[],int posS,int posE)
{
    if(posS>posE)
     return NULL;
    int rootdata=pos[posE];
    int lposS=posS;
    int rposE=posE-1;
    int rootIndex=search(pos,posS,posE-1,rootdata);
    int lposE=rootIndex-1;
    int rposS=rootIndex;
    Node *new_node=new Node(rootdata);
    new_node->left=constructTreehelper(pos,lposS,lposE);
    new_node->right=constructTreehelper(pos,rposS,rposE);
    return new_node;
}

Node *constructTree (int post[], int size)
{
  //code here
  return constructTreehelper(post,0,size-1); 
}