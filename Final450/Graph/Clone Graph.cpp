void clone(Node* node,Node* copy,vector<Node*> &vis)
    {
        vis[copy->val]=copy;
        for(auto x:node->neighbors)
        {
           
            if(vis[x->val]==NULL)
            {
                 Node* newNode=new Node(x->val);
                (copy->neighbors).push_back(newNode);
                clone(x,newNode,vis);
            }
            else
            {
                (copy->neighbors).push_back(vis[x->val]);
            }
        }
    }
    
    Node* cloneGraph(Node* node) {
        if(node==NULL)
            return NULL;
        vector<Node*> vis(1000,NULL);
        Node* copy=new Node(node->val);
        clone(node,copy,vis);
        return copy;
    }