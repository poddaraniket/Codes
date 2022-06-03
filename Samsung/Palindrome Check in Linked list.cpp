//O(N)

Node* findMiddle(Node* head)
    {
        Node* slow=head;
        Node* fast=head->next;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        Node* temp=slow->next;
        slow->next=NULL;
        return temp;
    }
    
    Node* reverse(Node *head)
    {
        Node *curr=head;
        Node *prev=NULL;
        Node *later=NULL;
        while(curr!=NULL)
         {
             later=curr->next;
             curr->next=prev;
             prev=curr;
             curr=later;
         }
        return prev; 
    }
    
    bool isPalindrome(Node *head)
    {
        //Your code here
        if(head->next==NULL)
         return true;
        if(head->next->next==NULL){
            return (head->data==head->next->data);
        } 
        Node *head2=findMiddle(head);
        head2=reverse(head2);
        //cout<<head->data<<" "<<head2->data<<endl;
        while(head!=NULL && head2!=NULL)
         {
             if(head->data!=head2->data)
              return false;
            head=head->next;
            head2=head2->next;
         }
        return true;
    }