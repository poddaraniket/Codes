//O(N)

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL)
            return NULL;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node *node=NULL;
            int size=q.size();
            while(size--){
                Node *temp=q.front();
                q.pop();
                temp->next=node;
                node=temp;
                if(temp->right)
                    q.push(temp->right);
                if(temp->left)
                    q.push(temp->left);
            }
        }
        return root;
    }
};