struct node *reverse (struct node *head, int k)
    { 
        // Complete this methodcurr
        node *curr=head;
        node *prev=NULL;
        node *later=NULL;
        int count=0;
        while(curr!=NULL && count<k)
         {
             later=curr->next;
             curr->next=prev;
             prev=curr;
             curr=later;
             count++;
         }
        if(later!=NULL)
         head->next=reverse(later,k);
        return prev; 
    }