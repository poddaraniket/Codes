bool detectLoop(Node* head)
    {
       
       if(head==NULL || head->next==NULL)
        return false;
        Node* slow=head;
       Node* fast=head;
       slow=slow->next;
       fast=fast->next->next;
       while(fast!=NULL && fast->next!=NULL){
           if(slow==fast)
            return true;
           slow=slow->next;
           fast=fast->next->next;
       }
    }