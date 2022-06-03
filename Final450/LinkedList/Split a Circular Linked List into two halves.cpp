void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    // your code goes here
    Node *head2=NULL;

    Node *prev=NULL; 
    Node* temp=head;
    Node *slow=head;
    Node *fast=head;
    while(fast->next!=temp && fast->next->next!=temp){
        slow=slow->next;
        fast=fast->next->next;
    }
    if(fast->next->next==temp){
        fast=fast->next;
    }
    
    *head1_ref=head;
    
    if(head->next!=head){
        *head2_ref=slow->next;
    }
    
    fast->next=slow->next;
    slow->next=head;
}