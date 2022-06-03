//O(N)

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        //ListNode* curr=head;
        // head of the reversed LinkedList
        ListNode *newHead=reverseList(head->next);
        //join the tai of the reversed list wth the node that was before this in the original list 
        ListNode *headNext=head->next;
        headNext->next=head;
        head->next=NULL;
        return newHead;
    }
};