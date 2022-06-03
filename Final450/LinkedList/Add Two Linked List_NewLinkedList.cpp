Node* reverse(Node *head){
    Node *prev,*curr,*later;
    prev=later=NULL;
    curr=head;
    while(curr!=NULL){
        later=curr->next;
        curr->next=prev;
        prev=curr;
        curr=later;
    }
    head=prev;
    return head;
}


struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        Node *head=NULL;
        Node *temp=NULL;
        int carry=0,sum;
        first=reverse(first);
        second=reverse(second);
        while(first && second){
            sum=(first->data+second->data+carry);
           // cout<<"*"<<sum<<endl;
            carry=sum/10;
            sum%=10;
            if(head==NULL)
             {
                // cout<<sum<<endl;
                 head=new Node(sum);
                 temp=head;
                 //temp=temp->next;
             }
            else{
               // cout<<sum<<endl;
                temp->next=new Node(sum);
                temp=temp->next;
            } 
            first=first->next;
            second=second->next;
        }
        //cout<<"*"<<endl;
        while(first){
            sum=first->data+carry;
            carry=sum/10;
            sum%=10;
            temp->next=new Node(sum);
            temp=temp->next;
            first=first->next;
        }
        while(second){
            sum=second->data+carry;
            carry=sum/10;
            sum%=10;
            temp->next=new Node(sum);
            temp=temp->next;
            second=second->next;
        }
        if(carry>0){
            temp->next=new Node(carry);
            
        }
        // Node *temp1=head;
        // while(temp1){
        //     cout<<temp1->data<<endl;
        //     temp1=temp1->next;
        // }
        // head=reverse(temp);
        // temp1=head;
        // while(temp1){
        //     cout<<temp1->data<<endl;
        //     temp1=temp1->next;
        // }
        head=reverse(head);
        return head;
    }