/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends


/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/
int search(int in[],int start,int end,int x)
{
    for(int i=start;i<=end;i++)
     {
        if(in[i]==x)
         return i;
     }
    return -1;
}

Node *buildTreehelper(int in[],int post[],int inS,int inE,int posS,int posE)
{
    if(inS>inE)
     return NULL;
    int rootdata=post[posE];
    int rootIndex=search(in,inS,inE,rootdata); 
    int linS=inS;
    int linE=rootIndex-1;
    int rinS=rootIndex+1;
    int rinE=inE;
    int lposS=posS;
    int lposE=(linE-linS)+lposS;
    int rposS=lposE+1;
    int rposE=posE-1;
    Node *new_node=new Node(rootdata);
    new_node->left=buildTreehelper(in,post,linS,linE,lposS,lposE);
    new_node->right=buildTreehelper(in,post,rinS,rinE,rposS,rposE);
    return new_node;
 }



// Function should construct tree and return
// root of it.  in[] stores inorder traversal
// post[] stores postorder traversal.  n is
// size of these arrays
Node *buildTree(int in[], int post[], int n) {
    // Your code here
    return buildTreehelper(in,post,0,n-1,0,n-1);
}
