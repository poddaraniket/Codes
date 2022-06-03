int count(Node* head){
        int cnt=0;
        while(head!=NULL)
         {
             cnt++;
             head=head->next;
         }
        return cnt; 
    }
    
    Node* traverse(Node *head,int diff)
    {
        while(diff--)
        {
            head=head->next;
        }
        return head;
    }
    
    int intersectPoint(Node* head1, Node* head2)
    {
        // Your Code Here
        int count1=count(head1);
        int count2=count(head2);
        
        if(count1>count2)
         {
             head1=traverse(head1,count1-count2);
         }
        else if(count2>count1)
         {
             head2=traverse(head2,count2-count1);
         }
        while(head1!=head2)
         {
             head1=head1->next;
             head2=head2->next;
         }
        return head1->data; 
    }