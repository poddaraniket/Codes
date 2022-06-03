 bool isPalindrome(Node *head)
    {
      Node *slow=head;
      Node *fast=head;
      while(fast->next && fast->next->next){
          slow=slow->next;
          fast=fast->next->next;
      }
      Node *curr=slow->next;
      Node *later=NULL;
      Node *prev=NULL;
      while(curr){
          later=curr->next;
          curr->next=prev;
          prev=curr;
          curr=later;
      }
     slow->next=prev; 
     Node *temp=head;
     slow=slow->next;
     while(slow){
        if(slow->data!=temp->data)
          return false;
          slow=slow->next;
          temp=temp->next;
     }
     return true;