int search(int in[],int val,int s,int e){
        for(int i=s;i<=e;i++)
         {
             if(in[i]==val)
              return i;
         }
        return -1; 
    }

    Node* buildTreeHelper(int in[],int inS,int inE,int pre[],int preS,int preE){
        if(inS>inE)
         return NULL;
        int index=search(in,pre[preS],inS,inE);
        Node *root=new Node(pre[preS]);
        int LpreS=preS+1;
        int RpreE=preE;
        int LinS=inS;
        int LinE=index-1;
        int RinS=index+1;
        int RinE=inE;
        int LpreE=LinE-LinS+LpreS;
        int RpreS=LpreE+1;
        root->left=buildTreeHelper(in,LinS,LinE,pre,LpreS,LpreE);
        root->right=buildTreeHelper(in,RinS,RinE,pre,RpreS,RpreE);
        return root;
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        return buildTreeHelper(in,0,n-1,pre,0,n-1);
    }