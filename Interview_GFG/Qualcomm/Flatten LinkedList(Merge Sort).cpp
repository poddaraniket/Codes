 Node* merge(Node* left,Node *right)
    {
        if(left==NULL)
         return right;
        if(right==NULL)
         return left;
        Node *head=NULL;
        Node *temp=NULL;
        while(left!=NULL && right!=NULL){
           if(left->data<right->data)
             {
                 if(head==NULL)
                  {
                      head=left;
                      temp=head;
                  }
                 else
                  {
                      temp->bottom=left;
                      temp=temp->bottom;
                  }
                 left=left->bottom; 
             }
            else
             {
                if(head==NULL)
                  {
                      head=right;
                      temp=head;
                  }
                 else
                  {
                      temp->bottom=right;
                      temp=temp->bottom;
                  }
                 right=right->bottom; 
             } 
        }
        if(left!=NULL)
         temp->bottom=left;
        else if(right!=NULL)
         temp->bottom=right;
        return head; 
    }

    Node *flatten(Node *root)
    {
        // Your code here
        Node *head=NULL;
        Node *curr=root;
        Node *later=NULL;
        while(curr!=NULL)
         {
             later=curr->next;
             curr->next==NULL;
             head=merge(head,curr);
             curr=later;
         }
        return head; 
    }