//O(N)
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{

// Your code goes here
  if(root==NULL)
   return;
  if(root->key==key)
   {
       if(root->left!=NULL){
           Node *temp=root->left;
           while(temp->right!=NULL)
            {
                temp=temp->right;
            }
           pre=temp; //Max value at left subtree is predecessor    
       }
       if(root->right!=NULL){
           Node *temp=root->right;
           while(temp->left!=NULL)
            {
                temp=temp->left;
            }
           suc=temp; //Max value at left subtree is predecessor    
       }
       return;
   }
  if(root->key<key){
   pre=root;
   findPreSuc(root->right,pre,suc,key);
  }
  else
  {
      suc=root;
      findPreSuc(root->left,pre,suc,key);   
  }