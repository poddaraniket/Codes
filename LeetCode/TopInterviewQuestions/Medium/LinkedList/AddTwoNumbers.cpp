class Solution {
public:
    
    int count(ListNode* l){
        int c=0;
        while(l!=NULL){
            c++;
            l=l->next;
        }
        return c;
    }
    
    void addTwoNumbersUtil(ListNode* l1, ListNode* l2){
        int carry=0;
        ListNode* temp1=l1; 
        ListNode* temp2=l2;
        ListNode* temp=NULL;
        while(temp1!=NULL){
            int sum=temp1->val+carry;
            if(temp2!=NULL){
                sum+=temp2->val;
                temp2=temp2->next;
            }
            temp1->val=sum%10;
            carry=sum/10;
            temp=temp1;
            temp1=temp1->next;
        }
        if(carry>0){
            ListNode *newNode=new ListNode(carry);
            temp->next=newNode;
        }
    }
    
    
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int count1=count(l1);
        int count2=count(l2);
        if(count1>=count2){
            addTwoNumbersUtil(l1,l2);
            return l1;
        }
        else{
            addTwoNumbersUtil(l2,l1);
            return l2;
        }
    }
};