/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    
    int count(ListNode *head){
        int len=0;
        while(head!=NULL){
            len++;
            head=head->next;
        }
        return len;
    }
    
    ListNode* traverseSinlge(ListNode *head,int steps){
        while(steps--){
            head=head->next;
        }
        return head;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int sizeA=count(headA);
        int sizeB=count(headB);
        if(sizeA>sizeB){
            headA=traverseSinlge(headA,sizeA-sizeB);
            headB=headB;
        }else{
            headA=headA;
            headB=traverseSinlge(headB,sizeB-sizeA);
        }
        
        while(headA!=headB){
            headA=headA->next;
            headB=headB->next;
        }
        return headA;
    }
};