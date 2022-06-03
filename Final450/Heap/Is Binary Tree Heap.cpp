bool isComplete(Node* tree){
        queue<Node*> que;
        que.push(tree);
        bool leftFill=false;
        while(!que.empty()){
            Node* temp=que.front();
            que.pop();
            if(temp->left!=NULL){
                leftFill=true;
                que.push(temp->left);
            }
            if(temp->right!=NULL){
                if(!leftFill)
                 return false;
                leftFill=false;
                que.push(temp->right);
            }
        }
        return true;
}

bool isHeapUtil(Node *temp){
    if(temp->left==NULL && temp->right==NULL)
     return true;
    
    if(temp->right==NULL){
        if(temp->data>temp->left->data)
          return true;
    }
    else{
        return (isHeapUtil(temp->left) && isHeapUtil(temp->right) && ((temp->left->data<temp->data) && (temp->right->data<temp->data)));
    }
    
}
  
    bool isHeap(struct Node * tree)
    {
        // code here
        return (isComplete(tree) && isHeapUtil(tree));
    }