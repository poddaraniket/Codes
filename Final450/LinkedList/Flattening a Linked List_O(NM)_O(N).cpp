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
   Node *temp=root;
   int count=0;
   vector<Node*> v;
   while(root!=NULL)
    {
        Node *temp=root->next;
        v.push_back(root);
        root->next=NULL;
        root=temp;
    }
   Node *ans=NULL;    
   for(int i=0;i<v.size();i++)
    {
        //<<v[i]->data<<endl;
        ans=merge(ans,v[i]);
    }
   return ans;    
}

