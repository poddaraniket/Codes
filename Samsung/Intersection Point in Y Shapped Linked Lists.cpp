//O(max(N,M))

int size(Node *head)
{
    int size=0;
    while(head!=NULL)
     {
         size++;
         head=head->next;
     }
     return size;
}

Node *traverse(Node *head,int diff)
{
    while(diff>0)
    {
        head=head->next;
        diff--;
    }
    return head;
}


int intersectPoint(Node* head1, Node* head2)
{
    int size1=size(head1);
    int size2=size(head2);
    int diff=abs(size1-size2);
    if(size1>size2)
      head1=traverse(head1,diff);
    else 
      head2=traverse(head2,diff);
    while(head1!=head2)
     {
        head1=head1->next;
        head2=head2->next;
     }
    return head1->data; 
}
