void removeLoop(Node* head)
    {
        // code here
        // just remove the loop without losing any nodes
        if(head==NULL || head->next==NULL){
            return;
        }
        Node *slow=head;
        Node *fast=head;
        
        slow=slow->next;
        fast=fast->next->next;
        
        while(fast && fast->next){
            if(slow==fast)
              break;
            slow=slow->next;
            fast=fast->next->next;
        }
        if(slow==head){
            while(fast->next!=slow){
                fast=fast->next;
            }
            fast->next=NULL;
        }else if(slow==fast){
            slow=head;
            while(slow->next!=fast->next){
                slow=slow->next;
                fast=fast->next;
            }
            fast->next=NULL;
        }
        
    }