
// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


 // } Driver Code Ends


/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class solver
{
private:

public:

    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        // return the sorted vector of all nodes at k dist
        Node *start=NULL;
        queue<Node*> q;
        unordered_map<Node*,Node*> mp;
        unordered_map<Node*,int> seen;
        q.push(root);
        while(!q.empty())
         {
            Node *temp=q.front();
            if(temp->data==target)
             start=temp;
            q.pop();
            if(temp->left) 
             {
                q.push(temp->left);
                mp[temp->left]=temp;
             }
            if(temp->right)
             {
                q.push(temp->right);
                mp[temp->right]=temp;
             }
         }
        int curr=0;
        queue<Node*> qi;
        qi.push(start);
        while(curr!=k)
        {
            int size=qi.size();
            //cout<<"/"<<endl;
            while(size--)
             {
                Node *temp=qi.front();
                qi.pop();
                //cout<<temp->data<<" ";
                seen[temp]=1;
                if(temp->left)
                 {
                    if(seen[temp->left]!=1)
                     qi.push(temp->left);
                 }
                if(temp->right)
                 {
                    if(seen[temp->right]!=1)
                     qi.push(temp->right);
                 }
                if(mp[temp]!=0)
                 {
                    if(seen[mp[temp]]!=1)
                     qi.push(mp[temp]);
                 }
             }
        ++curr;      
        }
       //cout<<"*"<<endl;    
       vector<int> v;
       Node *sear=NULL;
       while(!qi.empty())
       {
         sear=qi.front();  
         v.push_back(sear->data);
         qi.pop();
       }
       sort(v.begin(),v.end());
       return v;      
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    solver x = solver();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int target, k;
        cin>> target >> k;
        getchar();
        
        vector <int> res = x.KDistanceNodes(head, target, k);
        
        for( int i=0; i<res.size(); i++ )
            cout<< res[i] << " ";
        cout<<endl;
    }
    return 0;
}
  // } Driver Code Ends