#include<bits/stdc++.h>
using namespace std;
 
/* A binary search tree Node has data, pointer
   to left child and a pointer to right child */
struct Node
{
    int data;
    struct Node* left, *right;
};
 
// A utility function to create a new BST node
struct Node *newNode(int item)
{
    struct Node *temp =  new Node;
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}
 
/* A utility function to insert a new node with
   given key in BST */
struct Node* insert(struct Node* node, int key)
{
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(key);
 
    /* Otherwise, recur down the tree */
    if (key < node->data)
        node->left  = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);
 
    /* return the (unchanged) node pointer */
    return node;
}

int countNodes(Node *root){
    if(root==NULL)
     return 0;
    return countNodes(root->left)+countNodes(root->right)+1; 
}

void findVal(Node *root,int &k,int &c){
    if(root==NULL)
     return;
    findVal(root->left,k,c);
    k--;
    //cout<<"*"<<k<<" "<<root->data<<endl;
    if(k==0){
       // cout<<root->data<<endl;
             c=root->data;   
    }
    findVal(root->right,k,c); 
}

int findMedian(Node *root){
    if(root==NULL)
     return 0;
    int count=countNodes(root);
    int a,b;
    //findVal(root,(count/2)+1,a);
    if(count%2==0)
     {
        int count1=count/2;
        cout<<count1<<endl;
        findVal(root,count1,a);
        int count2=(count/2)+1;
        cout<<count2<<endl;
        findVal(root,count2,b);
        return (a+b)/2;
     }
    else{
        count++;
        count/=2;
        findVal(root,count,a);
       // cout<<a<<endl;
        return a;
    } 
}

int main()
{
 
    /* Let us create following BST
                  50
               /     \
              30      70
             /  \    /  \
           20   40  60   80 */
    struct Node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    insert(root,90);
 
    cout << "\nMedian of BST is "
         << findMedian(root);
    return 0;
}