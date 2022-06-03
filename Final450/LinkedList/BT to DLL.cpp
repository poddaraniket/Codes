// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(H).

// This function should return head to the DLL
class Solution
{
    public: 
    
    // Left will point to prev and right will point to next
    Node *headList=NULL;
    Node *prev=NULL;
    
    void bToDLLUtil(Node *root)
     {
         if(root==NULL)
          return;
         bToDLLUtil(root->left);
         if(prev==NULL)
          {
              headList=root;
              prev=root;
          }
         else
          {
              root->left=prev;
              prev->right=root;
              prev=root;
          }
        bToDLLUtil(root->right);  
     }
    
    //Function to convert binary tree to doubly linked list and return it.
    Node * bToDLL(Node *root)
    {
        bToDLLUtil(root);
        return headList;
    }
};