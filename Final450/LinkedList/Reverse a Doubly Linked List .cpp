Node* reverseDLL(Node * head)
{
    //Your code here
    Node *pre=NULL;
    Node *curr=head;
    Node *later=NULL;
    while(curr)
     {
        later=curr->next;
        curr->next=pre;
        curr->prev=later;
        pre=curr;
        curr=later;
     }
    head=pre;
    return head;
}