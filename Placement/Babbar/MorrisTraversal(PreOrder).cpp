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
    //Case 1:
      if(curr->left==NULL){
         // if no left then that is the root
          v.push_back(curr->data);
          curr=curr->right;
      }
      else{
        //Case 2 & 3 find the predecessor first
         Node *predecesor=find(curr);
         // add temp link
         //case 2: if already connected it to its parent
         if(predecesor->right==NULL){
            // when we mark the predecessor it means that is the root
             v.push_back(curr->data);
             predecesor->right=curr;
             curr=curr->left;
         }
         //remove temp link
         else{
            //case 2: if already connected it to its parent
            predecesor->right=NULL;
            curr=curr->right;
         }
      }
      
  }
  return v;
}