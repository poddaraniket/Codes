 Node* temp=head;
    while(temp!=NULL && temp->next!=NULL){
        if(temp->data==temp->next->data){
            temp->next=temp->next->next;
            continue;
        }
        temp=temp->next;
    }
    return head;