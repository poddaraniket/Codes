/*

In Inorder we go left so go right b4 going create a thread between right and root and then go left
what we do is we connect the last node of evry subtree to its parent

case 1 : if(left is null we don't have to create any node as we wont be going back there)
         so print that and go right
case 2: if left is not null before we go to the left(once we go we will not be able to connect) 
        we take its left child's right most element ans connect it to itself.
case 3: when we go from last node to parent again in iterative manner how do we
        know if we have to left or right, if coonection is there remove it and go right        

*/




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
            //case 1:
            if(curr->left==NULL){
                v.push_back(curr->data);
                curr=curr->right;
            }
            // create temp link
            //Case 2 & 3 find the predecessor first
            else{
                Node *predecesor=find(curr);
                //case 2: connect it to ts parent
                if(predecesor->right==NULL){
                    predecesor->right=curr;
                    curr=curr->left;
                }
                // remove the temp link
                //case 2: if already connected it to its parent
                else{
                    predecesor->right=NULL;
                    v.push_back(curr->data);
                    curr=curr->right;
                }
            }
        }
        return v;
    }