Node * removeDuplicates( Node *head) 
    {
      map<int,int> mp;
      Node *temp=head;
      Node *prev=NULL;
      while(temp!=NULL){
          if(mp[temp->data]==0){
              mp[temp->data]=1;
              prev=temp;
              temp=temp->next;
          }else{
              prev->next=temp->next;
              temp=prev->next;
          }
      }
      return head;
    }