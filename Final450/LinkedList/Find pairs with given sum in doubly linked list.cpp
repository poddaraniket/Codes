#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next, *prev;
};

void pairSum(Node *head, int x)
{
    Node *last=head;
    while(last->next!=NULL){
        last=last->next;
    }
    Node *first=head;
    while(first!=last){
        if(first->data+last->data==x)
         {
            cout<<first->data<<" "<<last->data<<endl; 
            first=first->next;
            last=last->prev;
         }
        else if(first->data+last->data>x)
         {
             last=last->prev;
         }
        else{
            first=first->next;
        } 
    }
}
  
void insert(Node **head, int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = temp->prev = NULL;
    if (!(*head))
        (*head) = temp;
    else
    {
        temp->next = *head;
        (*head)->prev = temp;
        (*head) = temp;
    }
}  
  
// Driver program to test above functions
int main()
{
    Node *head = NULL;
    insert(&head, 9);
    insert(&head, 8);
    insert(&head, 6);
    insert(&head, 5);
    insert(&head, 4);
    insert(&head, 2);
    insert(&head, 1);
    int x = 7;
 
    pairSum(head, x);
 
    return 0;
}
