Node* reverse(Node* head){
    Node *prev=NULL;
    Node *curr=head;
    Node *later=NULL;
    while(curr!=NULL){
        later=curr->next;
        curr->next=prev;
        prev=curr;
        curr=later;
    }
    head=prev;
    return head;
}

Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
       head=reverse(head);
       int carry=1;
       Node *prev=NULL;
       Node* temp=head;
       while(carry>0 && temp!=NULL){
           int sum=temp->data+carry;
           temp->data=sum%10;
           carry=sum/10;
           prev=temp;
           temp=temp->next;    
       }
       if(carry>0)
         {
           prev->next=new Node(carry);
         }
       head=reverse(head);
       return head;
    }