#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next, *prev;
};
  
// function to get a new node
Node* getNode(int data)
{
    // allocate space
    Node* new_node = (Node*)malloc(sizeof(Node));
  
    // put in the data
    new_node->data = data;
    new_node->next = new_node->prev = NULL;
    return new_node;
}

void push(Node** head_ref, Node* new_node)
{
    // since we are adding at the beginning,
    // prev is always NULL
    new_node->prev = NULL;
  
    // link the old list off the new node
    new_node->next = (*head_ref);
  
    // change prev of head node to new node
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;
  
    // move the head to point to the new node
    (*head_ref) = new_node;
}
 
 
Node* revListInGroupOfGivenSize(Node* head, int k)
{
    if(head==NULL)
     return NULL;
    int c=0;
    head->prev=NULL;
    Node *curr=head;
    Node *newhead=NULL;
    Node *pre=NULL,*later=NULL;
    while(curr!=NULL && c<k)
     {
        //newhead=curr;
        later=curr->next;
        curr->next=pre;
        curr->prev=later;
        pre=curr;
        curr=later;
        c++;
        //cout<<pre->data<<endl;
     }
    newhead=pre; 
    if(c>=k) 
      head->next=revListInGroupOfGivenSize(curr,k);
    return newhead;
} 

// given doubly linked list
void printList(Node* head)
{
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}
 

int main()
{
    // Start with the empty list
    Node* head = NULL;
  
    // Create doubly linked: 10<->8<->4<->2
    push(&head, getNode(2));
    push(&head, getNode(4));
    push(&head, getNode(8));
    push(&head, getNode(10));
     
    int k = 3;
  
    cout << "Original list: ";
    printList(head);
  
    // Reverse doubly linked list in groups of
    // size 'k'
    head = revListInGroupOfGivenSize(head, k);
  
    cout << "\nModified list: ";
    printList(head);
  
    return 0;
}
