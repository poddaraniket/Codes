#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
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
    Node* root = new Node(stoi(ip[0]));
        
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
            currNode->left = new Node(stoi(currVal));
                
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
            currNode->right = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}

bool isCousins(Node*root , int x , int y);

int main()
{

    int t;
	scanf("%d ",&t);
    while(t--)
    {
        string s;
		getline(cin,s);
        Node* root = buildTree(s);
        int x , y;
        scanf("%d ",&x);
		scanf("%d ",&y);
        if(x==y)
        {
            cout<<"0\n";
            continue;
        }
        cout <<isCousins(root,x,y)<< endl;
    }
    return 1;
}// } Driver Code Ends


/*Complete the function below
Node is as follows:
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
// Returns true if the nodes with values 'a' and 'b' are cousins. Else returns false
bool isCousins(Node *root, int a, int b)
{
   //add code here.
   int c=0;
   vector<pair<int,int>> ac,bc;
   queue<Node *> q;
   queue<int> level;
   q.push(root);
   level.push(1);
   if(root->data==a || root->data==b)
    return false;
   while(!q.empty())
    {
       Node *temp=q.front();
       int lev=level.front();
       q.pop();
       level.pop();
       if(temp->left!=NULL)
        {
           if(temp->left->data==a)
            {
             ac.push_back(make_pair(temp->data,lev));
            }
           if(temp->left->data==b)
           {
            bc.push_back(make_pair(temp->data,lev));   
           }
           q.push(temp->left);
           level.push(lev+1);
        }
       if(temp->right!=NULL)
        {
           if(temp->right->data==b)   
            bc.push_back(make_pair(temp->data,lev));
           if(temp->right->data==a)
            ac.push_back(make_pair(temp->data,lev));
           q.push(temp->right);    
           level.push(lev+1);
        }
       if(ac.size()!=0 && bc.size()!=0)
       {
        c=1;
        break;
       }
    }
   if(c==1)
    {
        if(ac[0].second==bc[0].second && ac[0].first!=bc[0].first)
         return true;
    }
   return false;    
}