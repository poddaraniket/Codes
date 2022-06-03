#include <bits/stdc++.h>
using namespace std;

int start=0;
bool neg=false;

struct Node {
    int data;
    Node *left, *right;
};

void preOrder(Node* node)
{
    if (node == NULL)
        return;
    printf("%d ", node->data);
    preOrder(node->left);
    preOrder(node->right);
}

Node* newNode(int data)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}
 

Node* treeFromStringHelper(string s){
    if(start>=s.length())
     return NULL;
    
    if(s[start]=='-')
     {
        start++;
        neg=true;
     }
    // creating number 
    int num=0; 
    while(start<s.length() && (s[start]>='0' && s[start]<='9')){
        int digit=s[start]-'0';
        num=num*10+digit;
        start++;
    }
    if(neg)
     num=-num;
     
    Node* root=newNode(num); 
    if(start>=s.length())
     return root;

    // Go left first for '('
    if(start<s.length() && s[start]=='(')
    {
        start++;
        root->left=treeFromStringHelper(s); 
    }
    if(start<s.length() && s[start]==')')
    {
        start++;
        return root; 
    }

    // Second time go right coz left is filled
    if(start<s.length() && s[start]=='(')
    {
        start++;
        root->right=treeFromStringHelper(s); 
    }
    
    if(start<s.length() && s[start]==')')
    {
        start++;
        return root; 
    }
    return root;
}

Node* treeFromString(string s){
    if(s.length()==0)
     return NULL;
    return treeFromStringHelper(s); 
}


int main()
{
    string str = "4(2(3)(1))(6(5))";
    Node* root = treeFromString(str);
    preOrder(root);
}