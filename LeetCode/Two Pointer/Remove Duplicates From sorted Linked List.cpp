 ListNode* deleteDuplicates(ListNode* head) {
        ListNode *curr=NULL,*later=NULL;
        curr=head;
        if(curr==NULL)
            return head;
        later=curr->next;
        //cout<<curr->val<<" "<<later->val<<endl;
        while(later!=NULL)
        {
            if(curr->val==later->val)
             {
                later=later->next;
                curr->next=later;
             }
            else
            {
                curr=curr->next;
                later=later->next;
            }
        }
        return head;
    }