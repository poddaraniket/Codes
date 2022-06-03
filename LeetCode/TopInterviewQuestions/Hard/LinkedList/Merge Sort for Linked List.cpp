//O(NlogN)

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


 // } Driver Code Ends


/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/

Node* merge(Node *first,Node *second)
{
    Node *temp=NULL;
    Node *new_list=NULL;
    if(first==NULL)
     return second;
    if(second==NULL)
     return first;
    if(first->data>second->data)
     {
        temp=second;
        second=temp->next;
     }
    else
     {
        temp=first;
        first=temp->next; 
     }
    new_list=temp; 
    while(first && second)
     {
        if(first->data<=second->data)
         {
            temp->next=first;
            temp=first;
            first=temp->next;
         }
        else
         {
            temp->next=second;
            temp=second;
            second=temp->next; 
         }
     }
    if(first==NULL)
     temp->next=second;
    else
     temp->next=first;
    return new_list; 
}

Node* Find_Middle(Node *head)
{
    //cout<<"*"<<endl;
    // if(head==NULL)
    //  return NULL;
    Node *mid=head,*fast=head->next;
    while(fast!=NULL && fast->next!=NULL)
     {
        fast=fast->next->next;
        mid=mid->next;
     }
    return mid;
}

/* Function to mergesort the linked list
   It should return head of the modified list  */
Node* mergeSort(Node* head) {
    // your code here
   // cout<<head->data<<endl;
    if(head==NULL || head->next==NULL)
     return head;
    //cout<<"*"<<endl; 
    Node *mid=Find_Middle(head);
    Node *mid_nxt=mid->next;
   // cout<<mid->data<<" "<<mid_nxt->data<<endl;
    mid->next=NULL;
    //cout<<mid->data<<" "<<mid_nxt->data<<endl;
    Node *first=mergeSort(head);
    Node *second=mergeSort(mid_nxt);
    
    Node *sortedList=merge(first,second);
    
    return sortedList;
    
}


// { Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        a = mergeSort(a);
        printList(a);
    }
    return 0;
}  // } Driver Code Ends