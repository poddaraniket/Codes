/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    int count(ListNode* head){
        int c=0;
        while(head){
            c++;
            head=head->next;
        }
        return c;
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int total=count(head);
        if(n==total){
            return head->next;
        }
        total-=n;
        ListNode* temp=head;
        while(total>1){
            temp=temp->next;
            total--;
        }
        // cout<<temp->val<<endl;
        temp->next=temp->next->next;
        return head;
    }
};