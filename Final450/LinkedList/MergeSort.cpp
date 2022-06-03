Node* merge(Node* first,Node* second)
    {
        Node* answer=NULL;
        if(first==NULL)
         return second;
        if(second==NULL)
         return first;
        if(first->data<=second->data)
        {
            answer=first;
            answer->next=merge(first->next,second);
        }
        else
         {
            answer=second;
            answer->next=merge(first,second->next);
         }
    }
    //,Node** first,Node** second
    void middle(Node* head,Node** first,Node** second)
    {
        //cout<<"*"<<endl;
        Node *slow=head;
        Node *fast=head->next;
        while(fast!=NULL)
         {
            fast=fast->next;
            if(fast!=NULL)
            {
             slow=slow->next;
             fast=fast->next;
            }
         }
        //cout<<slow->data<<" "<<slow->next->data<<endl; 
        *first=head;
        *second=slow->next;
        slow->next=NULL;
        //return slow; 
    }
    
    void mergingSort(Node** head){
        Node *curr=*head;
        Node *first;
        Node *second;
        if(curr==NULL || curr->next==NULL)
         {
             return;
         }
        middle(curr,&first,&second);
       // cout<<first->data<<" "<<second->data<<endl;
        mergingSort(&first);
        mergingSort(&second);
        *head=merge(first,second);
    }
    
    Node* mergeSort(Node* head) {
        // your code here
        mergingSort(&head);
        return head;
    }