#include <bits/stdc++.h>
using namespace std;

struct Node
{
    struct Node *left, *right;
    int data;
};

bool areAnagrams(Node *root1, Node *root2){
    if(root1==NULL && root2==NULL)
     return true;
    if(root1==NULL || root2==NULL)
     return false;
     
    queue<Node *> q1,q2;
    q1.push(root1);
    q2.push(root2);
    while(1)
     {
        int n1=q1.size();
        int n2=q2.size();
        if(n1!=n2)
         return false;
        if(n1==0)
         break;
        vector<int> level1,level2; 
        while(n1--)
         {
            Node *temp=q1.front();
            q1.pop();
            if(temp->left!=NULL)
             q1.push(temp->left);
            if(temp->right!=NULL)
             q1.push(temp->right);
            level1.push_back(temp->data); 
            
            temp=q2.front();
            q2.pop();
            if(temp->left!=NULL)
             q2.push(temp->left);
            if(temp->right!=NULL)
             q2.push(temp->right); 
            level2.push_back(temp->data);  
         }
        sort(level1.begin(),level1.end());
        sort(level2.begin(),level2.end());
        if(level1!=level2)
         return false;
     }
    return true; 
}

Node* newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
  
// Driver program to test above functions
int main()
{
    // Constructing both the trees.
    struct Node* root1 = newNode(1);
    root1->left = newNode(3);
    root1->right = newNode(2);
    root1->right->left = newNode(5);
    root1->right->right = newNode(4);
  
    struct Node* root2 = newNode(1);
    root2->left = newNode(2);
    root2->right = newNode(3);
    root2->left->left = newNode(4);
    root2->left->right = newNode(5);
  
    areAnagrams(root1, root2)? cout << "Yes" : cout << "No";
    return 0;
}
