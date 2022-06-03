int findFirstNode(Node* head)
    {
        // your code here
        if(head==NULL || head->next==NULL)
         return -1;
        Node* slow=head;
        Node* fast=head;
        slow=slow->next;
        fast=fast->next->next;
        while(fast && fast->next)
        {
            if(slow==fast)
             break;
            slow=slow->next;
            fast=fast->next->next; 
        }
        if(slow!=fast)
         return -1;
        slow=head;
        while(slow!=fast)
         {
             slow=slow->next;
             fast=fast->next;
         }
        return slow->data; 
    }