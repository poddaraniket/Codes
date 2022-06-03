Node *reverse(Node *head){
        Node *curr=head;
        Node *prev=NULL,*next=NULL;
        while(curr!=NULL)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        head=prev;
        return head;
    }
    
    Node *compute(Node *head)
    {
        // your code goes here
        head=reverse(head);
        //remove elements
        Node *curr=head;
        Node *prev=head;
        int maxi=head->data;
        head=head->next;
        while(head!=NULL)
         {
            if(head->data<maxi)
             {
                prev->next=head->next;
             }
            else
             {
                 prev->next=head;
                 maxi=head->data;
                 prev=prev->next;
             }
            head=head->next;
         }
        head=reverse(curr);
        return head;
    }