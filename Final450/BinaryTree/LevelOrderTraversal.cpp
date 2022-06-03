vector<int> levelOrder(Node* node)
    {
      //Your code here
      vector<int> v;
      queue<Node*> pq,cq;
      pq.push(node);
      while(!pq.empty())
       {
           Node *temp=pq.front();
           pq.pop();
           v.push_back(temp->data);
           if(temp->left!=NULL)
            {
                cq.push(temp->left);
            }
           if(temp->right!=NULL)
            {
                cq.push(temp->right);
            }
           if(pq.empty())
           {
              // cout<<"*"<<endl;
               pq.swap(cq);
           }
       }
      return v; 
    }