bool isCircular(Node *head)
{
   // Your code here
   if(head==NULL)
    return true;
   Node *temp=head;    
   while(head)
    {
       if(head->next==temp)
        return true;
       head=head->next;       
    }
    return false;    
}