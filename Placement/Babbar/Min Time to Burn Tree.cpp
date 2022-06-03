//O(N) ; O(|Height of tree|)

void traversal(Node *root,Node* &tar,map<Node*,Node*> &par,map<Node*,bool> &vis,int target){
        queue<Node*> q;
        q.push(root);
        par[root]=NULL;
        vis[root]=false;
        while(!q.empty()){
            Node *parent=q.front();
            q.pop();
            if(parent->data==target){
                tar=parent;
            }
            if(parent->left!=NULL){
                par[parent->left]=parent;
                vis[parent->left]=false;
                q.push(parent->left);
            }
            if(parent->right!=NULL){
                par[parent->right]=parent;
                vis[parent->right]=false;
                q.push(parent->right);
            }
        }
    }
    
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        Node *tar=NULL;
        map<Node*,Node*> parent;
        map<Node*,bool> vis;
        traversal(root,tar,parent,vis,target);
        int time=0;
        bool burned=false;
        queue<Node*> q;
        q.push(tar);
        while(!q.empty())
        {
            burned=false;
            int size=q.size();
            while(size--)
            {
                Node *temp=q.front();
                q.pop();
                
                //Burn Left Child
                if(temp->left && !vis[temp->left]){
                    burned=true;
                    vis[temp->left]=true;
                    q.push(temp->left);
                }
                //Burn Right Child
                if(temp->right && !vis[temp->right]){
                    burned=true;
                    vis[temp->right]=true;
                    q.push(temp->right);
                }
                //Burn Parent
                if(parent[temp] && !vis[parent[temp]]){
                    burned=true;
                    vis[parent[temp]]=true;
                    q.push(parent[temp]);
                }
            }
            if(burned)
             time++;
        }
        return time;
    }