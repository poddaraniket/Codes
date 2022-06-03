int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here 
    int count1=0,count2=0;
    Node *temp1=head1,*temp2=head2;
    while(temp1){
        temp1=temp1->next;
        count1++;
    }
    
    while(temp2){
        temp2=temp2->next;
        count2++;
    }
    
    if(count1>count2){
        while(count1-count2){
            head1=head1->next;
            count1--;
        }
    }else if(count1<count2){
        while(count2-count1){
            head2=head2->next;
            count2--;
        }
    }
    
    while(head1!=head2)
    {
        head1=head1->next;
        head2=head2->next;
    }
    return head1->data;
}