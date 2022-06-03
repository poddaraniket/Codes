Node* find(Node *root){
    Node *temp=root->left;
    while(temp->right!=NULL && temp->right!=root)
     temp=temp->right;
    return temp; 
}

vector <int> preorder(Node* root)
{
  // Your code here
  vector<int> v;
  Node *curr=root;
  while(curr!=NULL){
      if(curr->left==NULL){
          v.push_back(curr->data);
          curr=curr->right;
      }
      else{
         Node *predecesor=find(curr);
         // add temp link
         if(predecesor->right==NULL){
             v.push_back(curr->data);
             predecesor->right=curr;
             curr=curr->left;
         }
         //remove temp link
         else{
            predecesor->right=NULL;
            curr=curr->right;
         }
      }
      
  }
  return v;
}