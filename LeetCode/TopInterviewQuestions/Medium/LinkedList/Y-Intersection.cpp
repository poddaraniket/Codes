class Solution {
public:
    
    int count(ListNode *head){
        int c=0;
        while(head!=NULL){
            c++;
            head=head->next;
        }
        return c;
    }
    
    ListNode *traverse(ListNode *head,int k){
        while(k--){
            head=head->next;
        }
        return head;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
      int count1=count(headA);
      int count2=count(headB);
      ListNode* head1=NULL;
      ListNode* head2=NULL;
      if(count1>count2){
          head1=traverse(headA,count1-count2);
          head2=headB;
      }else{
          head2=traverse(headB,count2-count1);
          head1=headA;
      }  
      while(head1!=head2){
          head1=head1->next;
          head2=head2->next;
      }
      return head1;  
    }
};