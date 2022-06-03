//O(N)

Node *copyList(Node *head)
    {
        //Write your code here
        Node *curr=head;
        while(curr)
         {
             Node *later=curr->next;
             Node *newNode=new Node(curr->data);
             curr->next=newNode;
             newNode->next=later;
             curr=later;
         }
        // set random pointers 
        curr=head; 
        while(curr)
        {
            if(curr->next)
              curr->next->arb= (curr->arb) ? curr->arb->next : curr->arb;
            curr=(curr->next) ? curr->next->next : curr->next;  
        }

        // seperate original from copy

        Node *original=head;
        Node *cloned=head->next;
        Node *ans=cloned;
        while(original && cloned)
         {
             original->next= original->next ? original->next->next : original->next;
             cloned->next= cloned->next ? cloned->next->next : cloned->next;
             original=original->next;
             cloned=cloned->next;
         }
        return ans; 
    }