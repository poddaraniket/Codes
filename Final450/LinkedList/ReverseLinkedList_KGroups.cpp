struct node *reverse (struct node *head, int k)
    { 
        int count=k;
        node *prev=NULL;
        node *later=NULL;
        node *curr=head;
        while(curr!=NULL){
            if(k==0)
             break;
            later=curr->next;
            curr->next=prev;
            prev=curr;
            curr=later;
            k--;
        }
        
        if(later!=NULL){
            head->next=reverse(later,count);
        }
        
        return prev;
    } 