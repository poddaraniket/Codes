void reverse(vector<int> &v)
{
    int last=v.size()-1;
    int first=0;
    while(first<last)
    {
        swap(v[first],v[last]);
        first++;
        last--;
    }
}

vector<int> reverseLevelOrder(Node *root)
{
    // code here
      vector<int> v;
      queue<Node*> pq,cq;
      pq.push(root);
      while(!pq.empty())
       {
           Node *temp=pq.front();
           pq.pop();
           v.push_back(temp->data);
           if(temp->right!=NULL)
            {
                cq.push(temp->right);
            }
           if(temp->left!=NULL)
            {
                cq.push(temp->left);
            }
           if(pq.empty())
           {
              // cout<<"*"<<endl;
               pq.swap(cq);
           }
       }
      reverse(v); 
      return v; 
}