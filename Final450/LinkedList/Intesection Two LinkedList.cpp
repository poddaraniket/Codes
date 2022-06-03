Node* findIntersection(Node* head1, Node* head2)
{
    // Your Code Here
    Node *head=NULL;
    Node *temp=NULL;
    while(head1 && head2){
        if(head1->data<head2->data)
         {
            head1=head1->next;
         }
        else if(head1->data>head2->data)
         {
            head2=head2->next;
         }
        else{
            if(head==NULL)
             {
                head=new Node(head1->data);
                temp=head;
             }
            else
             {
                temp->next=new Node(head1->data);
                temp=temp->next;
             }
            head1=head1->next;
            head2=head2->next;
        }
    }
    return head;
}