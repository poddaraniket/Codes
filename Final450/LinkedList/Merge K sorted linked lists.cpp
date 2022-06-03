Node* merge(Node* first,Node* second)
    {
        Node* answer=NULL;
        if(first==NULL)
         return second;
        if(second==NULL)
         return first;
        if(first->data<=second->data)
         {
             answer=first;
             answer->next=merge(first->next,second);
         }
        else{
             answer=second;
             answer->next=merge(first,second->next);
        } 
    }
    
    Node * mergeKLists(Node *arr[], int K)
    {
           // Your code here
           Node* ans=NULL;
           for(int i=0;i<K;i++)
            {
                ans=merge(ans,arr[i]);
            }
        return ans;    
    }