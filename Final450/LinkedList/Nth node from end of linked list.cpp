int getNthFromLast(struct Node *head, int n)
{
    struct Node* temp=head;
    int count=0;
    while(temp!=NULL)
     {
         count++;
         temp=temp->next;
     }
    if(n>count)
      return -1;
    int reach=count-n;
    while(reach--)
    {
        head=head->next;
    }
    return head->data;
}