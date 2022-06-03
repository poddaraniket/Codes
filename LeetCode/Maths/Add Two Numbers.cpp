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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head=new ListNode(0);
        ListNode *temp=head;
        int sum=0,carry=0;
        while(l1!=NULL || l2!=NULL)
        {
            if(l1==NULL)
             {
                sum=(l2->val)+carry;
                carry=sum/10;
                l2=l2->next;
             }
            else if(l2==NULL)
             {
               sum=(l1->val)+carry;
               carry=sum/10; 
               l1=l1->next; 
             }
            else
             {
               sum=(l1->val)+(l2->val)+carry;
               carry=sum/10; 
                l2=l2->next;
                l1=l1->next; 
             }
            ListNode *new_node=new ListNode(sum%10);
            temp->next=new_node;
            temp=temp->next;
            
        }
        if(carry>0)
         {
           ListNode *new_node=new ListNode(carry);
           temp->next=new_node;
           temp=temp->next; 
         }
        return head->next;
    }
};