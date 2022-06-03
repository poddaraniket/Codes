#include<bits/stdc++.h>
using namespace std;
 
/* A binary tree node has data, pointer to left child
and a pointer to right child */
class node
{
    public:
    int data;
    node* left;
    node* right;
};

void printInorder(node* node)
{
    if (node == NULL)
        return;
 
    /* first recur on left child */
    printInorder(node->left);
 
    cout << node->data << " ";
 
    /* now recur on right child */
    printInorder(node->right);
}

void inorderStore(node *root,vector<int> &v){
    if(root==NULL)
     return;
    inorderStore(root->left,v);
    v.push_back(root->data);
    inorderStore(root->right,v);
} 
 
node* newNode(int data)
{
    node* Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;
 
    return(Node);
} 
 
vector<int> mergedArray(vector<int> v1,vector<int> v2)
{
    vector<int> v;
    int n=0,m=0;
    while(1)
    {
        if(n>=v1.size() || m>=v2.size())
         break;
        if(v1[n]<v2[m])
         {
            v.push_back(v1[n]);
            n++;
         }
        else if(v1[n]>v2[m])
         {
            v.push_back(v2[m]);
            m++; 
         }
        else
         {
            v.push_back(v1[n]);
            v.push_back(v2[m]);
            n++;
            m++;
         }
    }
    while(n<v1.size())
     {
        v.push_back(v1[n++]); 
     }
    while(m<v2.size())
     {
        v.push_back(v2[m++]); 
     }
    // for(int i=0;i<v.size();i++)
    //  cout<<v[i]<<" ";
    // cout<<endl; 
    return v; 
}
 
node* merge(vector<int> v,int s,int e){
    if(s>e)
     return NULL;
    int mid=(s+e)/2; 
    node* node=newNode(v[mid]);
    node->left=merge(v,s,mid-1);
    node->right=merge(v,mid+1,e);
    return node;
} 
 
node* mergeTrees(node* root1,node *root2,int n,int m)
{
    vector<int> v1,v2;
    inorderStore(root1,v1);
    inorderStore(root2,v2);
    
    vector<int> v=mergedArray(v1,v2);
    
    node *root=NULL;
    root=merge(v,0,v.size()-1);
    return root;
}

int main()
{
    /* Create following tree as first balanced BST
        100
        / \
        50 300
    / \
    20 70
    */
    node *root1 = newNode(100);
    root1->left     = newNode(50);
    root1->right = newNode(300);
    root1->left->left = newNode(20);
    root1->left->right = newNode(70);
 
    /* Create following tree as second balanced BST
            80
        / \
        40 120
    */
    node *root2 = newNode(80);
    root2->left     = newNode(40);
    root2->right = newNode(120);
 
    node *mergedTree = mergeTrees(root1, root2, 5, 3);
 
    cout << "Following is Inorder traversal of the merged tree \n";
    printInorder(mergedTree);
 
    return 0;
}