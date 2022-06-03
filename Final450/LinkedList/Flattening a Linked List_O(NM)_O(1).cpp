Node* merge(Node* first,Node* second)
{
    Node* ans=NULL;
    if(first==NULL)
     return second;
    if(second==NULL)
     return first;
    if(first->data<second->data){
        ans=first;
        ans->bottom=merge(first->bottom,second);
    }
    else{
        ans=second;
        ans->bottom=merge(first,second->bottom); 
    }
}
    
Node *flatten(Node *root)
{
   // Your code here
   if(root==NULL || root->next==NULL)
    return root;
   return merge(root,flatten(root->next));    
}