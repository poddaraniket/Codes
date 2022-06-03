Node* find(Node *node){
        Node *temp=node;
        temp=temp->left;
        while(temp->right!=NULL && temp->right!=node){
            temp=temp->right;
        }
        return temp;
    }

    vector<int> inOrder(Node* root)
    {
        //code here
        vector<int> v;
        Node* curr=root;
        while(curr!=NULL){
            if(curr->left==NULL){
                v.push_back(curr->data);
                curr=curr->right;
            }
            // create temp link
            else{
                Node *predecesor=find(curr);
                if(predecesor->right==NULL){
                    predecesor->right=curr;
                    curr=curr->left;
                }
                // remove the temp link
                else{
                    predecesor->right=NULL;
                    v.push_back(curr->data);
                    curr=curr->right;
                }
            }
        }
        return v;
    }