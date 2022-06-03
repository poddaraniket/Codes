//O(N)
Node *newNode(int data)
{
    Node *temp=(Node*)malloc(sizeof(Node));
    temp->data=data;
    temp->left=temp->right=NULL;
    return temp;
}

Node* constructNodeUtil(int pos[],int &index,int key,int mini,int maxi)
{
    if(index<0)
     return NULL;
    Node *root=NULL; 
    if(key>mini && key<maxi)
     {
        root=newNode(key);
        index-=1;
        if(index>=0){
         root->right=constructNodeUtil(pos,index,pos[index],key,maxi);
         root->left=constructNodeUtil(pos,index,pos[index],mini,key);
        }
     }
    return root; 
}

Node *constructTree (int post[], int size)
{
//code here
   int index=size-1;
   Node *root=constructNodeUtil(post,index,post[index],INT_MIN,INT_MAX);
   return root;
}