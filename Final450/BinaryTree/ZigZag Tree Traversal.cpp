vector <int> zigZagTraversal(Node* root)
{
	// Code here
	vector<int> v;
	if(!root)
	 return v;
	stack<Node*> pq,cq;
	bool level=true;
	pq.push(root);
	while(!pq.empty()){
	    Node *temp=pq.top();
	    pq.pop();
	    v.push_back(temp->data);
	    if(level){
	        if(temp->left!=NULL)
	         {
	             cq.push(temp->left);
	         }
	        if(temp->right!=NULL)
	         {
	             cq.push(temp->right);
	         }
	    }
	    else{
	        if(temp->right!=NULL)
	         {
	             cq.push(temp->right);
	         }
	        if(temp->left!=NULL)
	         {
	             cq.push(temp->left);
	         } 
	    }
	    if(pq.empty()){
	        level=!level;
	        pq.swap(cq);
	    }
	}
	return v;
}