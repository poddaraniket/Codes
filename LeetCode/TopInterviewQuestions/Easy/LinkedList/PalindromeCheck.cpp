class Solution {
public:
    
    ListNode* reverse(ListNode* head){
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* newHead=reverse(head->next);
        ListNode* headNxt=head->next;
        headNxt->next=head;
        head->next=NULL;
        return newHead;
    }
    
    ListNode* findMid(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    
    bool isPalindrome(ListNode* head) {
        if(head->next==NULL)
            return true;
        ListNode *mid=findMid(head);
        ListNode *first=head;
        ListNode *second=mid->next;
        mid->next=NULL;
         // cout<<first->val<<" "<<second->val<<endl;
        second=reverse(second);
         // cout<<first->val<<" "<<second->val<<endl;
        while(first!=NULL && second!=NULL){
            if(first->val!=second->val)
                return false;
            first=first->next;
            second=second->next;
        }
        return true;
    }
};