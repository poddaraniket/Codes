Node* segregate(Node *head) {
        
        // Add code herezero
        int count[3]={0};
        Node *temp=head;
        while(temp!=NULL)
         {
             count[temp->data]++;
             temp=temp->next;
         }
        temp=head; 
        int i=0;
        while(temp!=NULL)
        {
            if(count[i]==0)
             i++;
            else
            {
                temp->data=i;
                count[i]--;
                temp=temp->next;;
            }
        }
        return head;
    }