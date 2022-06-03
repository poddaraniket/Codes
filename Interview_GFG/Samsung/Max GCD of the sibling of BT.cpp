//O(N)

int gcd(int a,int b)
    {
        if(a==0)
         return b;
        return gcd(b%a,a); 
    }

    void maxGCDUtil(Node* root,int &d,int &v)
     {
         if(root==NULL)
          return;
         if(root->left!=NULL && root->right!=NULL)
          {
              int val=gcd(root->left->data,root->right->data);
              if(val>v){
               d=root->data;
               v=val;
              }
              else if(val==v)
               d=max(d,root->data);
          }
         maxGCDUtil(root->left,d,v);
         maxGCDUtil(root->right,d,v);
     }

    int maxGCD( Node* root)
    {
        //code here
        if(root==NULL)
         return -1;
        int d=0,v=0;
        maxGCDUtil(root,d,v);
        return d;
    }