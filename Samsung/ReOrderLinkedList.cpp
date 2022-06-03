//O(N)

void reorderList(ListNode* head) {
        deque<ListNode*> dq;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            ListNode* later=temp;
            temp=temp->next;
            later->next=NULL;
            dq.push_back(later);
        }
        head=NULL;
        while(dq.size()>1)
        {
            ListNode* first=dq.front();
            dq.pop_front();
            ListNode* second=dq.back();
            dq.pop_back();
            if(head==NULL)
             {
                head=first;
                temp=head;
             } 
            else
             {
                temp->next=first;
                temp=temp->next;
             }
            temp->next=second;
            temp=temp->next;
        }
        if(!dq.empty()){
           ListNode* node=dq.front();
           dq.pop_front();
           if(head==NULL){
               head=node;
           }
           else{
               temp->next=node;
           } 
        }   
    }