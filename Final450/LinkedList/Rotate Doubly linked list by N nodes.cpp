#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    struct Node* prev;
    struct Node* next;
};
 
 
// function to count triplets in a sorted doubly linked list
// whose sum is equal to a given value 'x'
void rotate(struct Node** head_ref, int N)
{
    if(N==0)
     return;
    Node *head=*head_ref;
    Node *temp=head;
    while(temp->next!=NULL)
     {
        temp=temp->next; 
     }
    Node *last=temp;
    while(N--)
    {
        Node *temp=*head_ref;
        last->next=temp;
        temp->prev=last;
        last=last->next;
        (*head_ref)=(*head_ref)->next;
    }
    (*head_ref)->prev=NULL;
    last->next=NULL;
}

void push(struct Node** head_ref, int new_data)
{
    struct Node* new_node =  new Node;
    new_node->data = new_data;
    new_node->prev = NULL;
    new_node->next = (*head_ref);
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;
   *head_ref = new_node;
}
 

void printList(struct Node* node)
{
    while (node->next != NULL) {
        cout << node->data << " "
             << "<=>"
             << " ";
        node = node->next;
    }
    cout << node->data;
}
 
// Driver program to test above
int main(void)
{
    /* Start with the empty list */
    struct Node* head = NULL;
 
    /* Let us create the doubly
      linked list a<->b<->c<->d<->e */
    push(&head, 'e');
    push(&head, 'd');
    push(&head, 'c');
    push(&head, 'b');
    push(&head, 'a');
 
    int N = 2;
 
    cout << "Given linked list \n";
    printList(head);
    rotate(&head, N);
 
    cout << "\nRotated Linked list \n";
    printList(head);
 
    return 0;
}