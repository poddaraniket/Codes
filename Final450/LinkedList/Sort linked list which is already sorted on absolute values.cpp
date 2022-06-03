#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node* next;
    int data;
};
 
// Utility function to insert a node at the
// beginning
void push(Node** head, int data)
{
    Node* newNode = new Node;
    newNode->next = (*head);
    newNode->data = data;
    (*head) = newNode;
}
 
// Utility function to print a linked list
void printList(Node* head)
{
    while (head != NULL)
    {
        cout << head->data;
        if (head->next != NULL)
            cout << " -> ";
        head = head->next;
    }
    cout<<endl;
}

void sortList(Node** head)
{
    Node *curr=(*head)->next;
    Node *prev=*head;
    while(curr!=NULL){
        Node *later=curr->next;
        if(curr->data<prev->data)
         {
            prev->next=later;
            curr->next=*head;
            *head=curr;
            curr=prev;
         }
        else
         prev=curr;
        curr=curr->next;
    }
}

int main()
{
    Node* head = NULL;
    push(&head, -5);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, -2);
    push(&head, 1);
    push(&head, 0);
 
    cout << "Original list :\n";
    printList(head);
 
    sortList(&head);
 
    cout << "\nSorted list :\n";
    printList(head);
 
    return 0;
}