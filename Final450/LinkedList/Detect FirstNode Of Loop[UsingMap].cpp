 ListNode *detectCycle(ListNode *head) {
        map<ListNode *,int> mp;
        ListNode *temp=head;
        while(temp!=NULL){
            if(mp[temp]==0){
                mp[temp]=1;
            }else{
                return temp;
            }
            temp=temp->next;
        }
        return NULL;
    }