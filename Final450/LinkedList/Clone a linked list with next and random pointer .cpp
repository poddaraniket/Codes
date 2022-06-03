Node *copyList(Node *head)
    {
        //Write your code here
        //addCopy(head);
        Node *curr=head;
        Node *temp;
        while(curr);
        {
            temp=curr->next;
            curr->next=new Node(curr->data);
            curr->next->next=temp;
            curr=temp;
        }
        curr=head;
       // addArb(head);
        while(curr)
         {
             curr->next->arb=curr->arb?curr->arb->next:curr->arb; 
             curr=curr->next->next;
         }
        // Seperate Original and Copy;
        Node *original=head;
        Node *copy=head->next;
        temp=copy;
        while(original!=NULL && copy!=NULL)
        {
            original->next=original->next->next;
            copy->next=copy->next?copy->next->next:copy->next;
            original=original->next;
            copy=copy->next;
        }
        return temp;
    }