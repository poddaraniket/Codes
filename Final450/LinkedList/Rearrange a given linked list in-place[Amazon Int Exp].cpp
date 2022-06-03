#include <bits/stdc++.h>
using namespace std;
 
// Linkedlist Node structure
struct Node {
    int data;
    struct Node* next;
};
 
// Function to create newNode in a linkedlist
Node* newNode(int key)
{
    Node* temp = new Node;
    temp->data = key;
    temp->next = NULL;
    return temp;
}
 
Node* findMiddle(Node *root)
{
    Node *prev=NULL;
    Node *curr=root;
    Node *later=root->next;
    while(later){
        if(later->next==NULL)
         break;
        prev=curr; 
        curr=curr->next;
        later=later->next->next;
    }
    return curr;
}
 
Node* reverse(Node *root){
    if(root==NULL || root->next==NULL)
     return root;
    Node *curr=root;
    Node *prev=NULL;
    Node *later=NULL;
    while(curr)
     {
        later=curr->next;
        curr->next=prev;
        prev=curr;
        curr=later;
     }
    root=prev;
    //cout<<"()"<<root->data<<endl;
    return root;
} 
 
void rearrange(Node **head)
{
    Node *root=*head;
    if(root==NULL || root->next==NULL)
     return;
    Node *prev=findMiddle(root);
    Node *mid=prev->next;
    // cout<<"*"<<mid->data<<endl;
    prev->next=NULL;
    Node *root1=reverse(mid);
    Node *temp1=root1;
    Node *temp=root;
    while(root && root1)
     {
        temp=root->next;
        temp1=root1->next;
        root->next=root1;
        if(temp!=NULL)
            root1->next=temp;
        root=temp;
        root1=temp1;
     }
    // while(root)
    //  {
    //     cout<<root->data<<endl; 
    //     root=root->next;
    //  }
    // cout<<"------"<<endl;
    // while(root1)
    //  {
    //     cout<<root1->data<<endl; 
    //     root1=root1->next;
    //  }
}
 
void printlist(Node* head)
{
    while (head != NULL) {
        cout << head->data << " ";
        if (head->next)
            cout << "-> ";
        head = head->next;
    }
    cout << endl;
} 
 
int main()
{
    Node* head = newNode(1);
    // head->next = newNode(2);
    // head->next->next = newNode(3);
    // head->next->next->next = newNode(4);
    // head->next->next->next->next = newNode(5);
 
    printlist(head); // Print original list
    rearrange(&head); // Modify the list
    printlist(head); // Print modified list
    return 0;
}