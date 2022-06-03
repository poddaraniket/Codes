Node* divide(int N, Node *head){
        // code here
        if(head==NULL)
         return NULL;
        Node *temp1=NULL,*temp=NULL;
        Node *even=NULL;
        Node *odd=NULL;
        Node *curr=head->next;
        while(head!=NULL)
         {
             if((head->data)%2==0)
             {
                //  cout<<"even"<<head->data<<endl;
                if(even==NULL)
                 {
                     even=head;
                     temp=even;
                 }
                else{
                    even->next=head;
                    even=even->next;
                }
             }
            else if((head->data)%2!=0)
             {
                //  cout<<"odd"<<head->data<<endl; 
                if(odd==NULL)
                 {
                     odd=head;
                     temp1=odd;
                 }
                else{
                   odd->next=head; 
                   odd=odd->next;
                }
             }
            head=head->next;
            // head=curr;
            // curr=curr->next;
         }
        //even->next=NULL;
        if(odd!=NULL)
          odd->next=NULL;
        if(temp!=NULL){
          head=temp; 
          even->next=temp1;
        }
        else
         head=temp1;
        return head;
    }