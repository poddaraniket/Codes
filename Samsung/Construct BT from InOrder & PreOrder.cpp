 Node *newNode(int data)
    {
        Node *temp=(Node*)malloc(sizeof(Node));
        temp->data=data;
        temp->left=temp->right=NULL;
        return temp;
    }
    
    int search(int in[],int s,int e,int val)
     {
         for(int i=s;i<=e;i++){
             if(in[i]==val)
              return i;
         }
        return -1; 
     }
    
    Node *buildTreeUtil(int in[],int pre[],int inS,int inE,int preS,int preE)
    {
         if(preS>preE)
           return NULL;
         int key=pre[preS];
         int index=search(in,inS,inE,key);
         Node *root=newNode(key);
         int LinS=inS;
         int LinE=index-1;
         int RinS=index+1;
         int RinE=inE;
         int LpreS=preS+1;
         int LpreE=(LinE-LinS)+LpreS;
         int RpreS=LpreE+1;
         int RpreE=preE;
         root->left=buildTreeUtil(in,pre,LinS,LinE,LpreS,LpreE);
         root->right=buildTreeUtil(in,pre,RinS,RinE,RpreS,RpreE);
         return root;
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        Node *root=buildTreeUtil(in,pre,0,n-1,0,n-1);
        return root;
    }