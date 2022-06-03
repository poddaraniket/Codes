class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* odd=head;
        ListNode* even=head->next;
        ListNode* temp=even;
        while(odd->next!=NULL && even->next!=NULL){
            if(even->next!=NULL)
             {
                odd->next=even->next;
                odd=odd->next;
             }
            if(odd->next!=NULL)
             {
                even->next=odd->next;
                even=even->next;
             }
        }
        even->next=NULL;
        odd->next=temp;
        return head;
    }
};