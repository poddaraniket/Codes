#include <bits/stdc++.h>

using namespace std;
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};

Node* buildTree(int inorder[], int levelOrder[], int iStart, int iEnd,int n);
void printPreorder(Node* node)
{
    if (node == NULL)
       return;
    cout << node->key << " ";
    printPreorder(node->left);
    printPreorder(node->right);
    
}
int main()
{
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    int in[n],level[n];
    for(int i=0;i<n;i++){
        cin>>in[i];
    }
    for(int i=0;i<n;i++){
        cin>>level[i];
    }
    Node *root=NULL;
    root = buildTree(in, level, 0, n - 1,n);
    printPreorder(root);
    cout<<endl;
    }
    return 0;
}// } Driver Code Ends


/*Complete the function below
Node is as follows:
struct Node
{
    int key;
    struct Node* left, *right;
};
*/

int search(int inorder[],int start,int end,int x)
{
    for(int i=start;i<=end;i++)
     {
        if(inorder[i]==x)
         return i;
     }
    return -1; 
}

Node *buildTreehelper(int inorder[],vector<int> level,int inS,int inE,int n)
{
    if(n<=0)
     return NULL;
    int rootdata=level[0];
    Node *new_node=new Node(rootdata);
    int rootIndex=search(inorder,inS,inE,rootdata);
    vector<int> llevel,rlevel;
    for(int i=1;i<n;i++)
     {
        int c=0; 
        for(int j=inS;j<rootIndex;j++)
         {
            if(level[i]==inorder[j])
            {
             c=1;
             llevel.push_back(level[i]);
             break;
            }
         }
        if(c==0)
         rlevel.push_back(level[i]);
     }
    new_node->left=buildTreehelper(inorder,llevel,inS,rootIndex-1,llevel.size());
    new_node->right=buildTreehelper(inorder,rlevel,rootIndex+1,inE,rlevel.size());
    return new_node;
}

Node* buildTree(int inorder[], int levelOrder[], int iStart, int iEnd,int n)
{
  //add code here.
  vector<int> lev;
  for(int i=0;i<n;i++)
   lev.push_back(levelOrder[i]);
  return buildTreehelper(inorder,lev,iStart,iEnd,n);  
}