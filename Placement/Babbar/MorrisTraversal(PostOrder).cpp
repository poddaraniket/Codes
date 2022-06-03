//Same as PreOrder just swap left to right and reverse the result

Node* find(Node *root){
    Node *temp=root->right;
    while(temp->left!=NULL && temp->left!=root)
     temp=temp->left;
    return temp; 
}

vector <int> postOrder(Node* root)
{
  // Your code here
  vector<int> v;
  Node *curr=root;
  while(curr!=NULL){
      if(curr->right==NULL){
          v.push_back(curr->data);
          curr=curr->left;
      }
      else{
         Node *sucessor=find(curr);
         // add temp link
         if(sucessor->left==NULL){
             v.push_back(curr->data);
             sucessor->left=curr;
             curr=curr->right;
         }
         //remove temp link
         else{
            sucessor->left=NULL;
            curr=curr->left;
         }
      }
      
  }
  reverse(v.begin(),v.end());
  return v;
}
