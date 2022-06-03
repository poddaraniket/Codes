class Solution {
public:
    
    ListNode* merge(ListNode* head1,ListNode* head2){
        if(head1==NULL)
            return head2;
        if(head2==NULL)
            return head1;
        ListNode* head=NULL;
        ListNode* temp=head;
        while(head1!=NULL && head2!=NULL){
            if(head1->val<=head2->val){
                if(head==NULL){
                    head=head1;
                    temp=head;
                }
                else{
                    temp->next=head1;
                    temp=temp->next;
                }
                head1=head1->next;
            }
            else{
                if(head==NULL){
                    head=head2;
                    temp=head;
                }
                else{
                    temp->next=head2;
                    temp=temp->next;
                }
                head2=head2->next;
            }
        }
        if(head2!=NULL){
            temp->next=head2;
        }else if(head1!=NULL){
            temp->next=head1;
        }
        return head;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head=NULL;
        for(int i=0;i<lists.size();i++){
            head=merge(head,lists[i]);
        }
        return head;
    }
};