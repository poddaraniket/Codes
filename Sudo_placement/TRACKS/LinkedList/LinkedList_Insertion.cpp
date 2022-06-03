#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
  }  
  cout<<"\n";
} 

Node *insertAtBegining(Node *head, int newData);
Node *insertAtEnd(Node *head, int newData);

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        struct Node *head = NULL;
        for (int i = 0; i < n; ++i)
        {
            int data, indicator;
            cin>>data;
            cin>>indicator;
            if(indicator)
                head = insertAtEnd(head, data); 
            else
                head = insertAtBegining(head, data);
        }
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends


/*Structure of the linked list node is as
struct Node {
  int data;
  struct Node * next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

Node *tail=NULL;

// function inserts the data in front of the list
Node *insertAtBegining(Node *head, int newData) {
   // Your code here
   Node *n=new Node(newData);
  if(head==NULL)
    {
        head=n;
        tail=n;
        return head;  // returns add of pointer n
    }
   n->next=head;
   head=n;    //inserts address of n to head making it the head pointer
   return head;
}


// function appends the data at the end of the list
Node *insertAtEnd(Node *head, int newData)  {
   // Your code here
   static Node *temp;
   Node *n=new Node(newData);
   if(head==NULL)
    {
        head=n;
        tail=n;
        return head;
    }
   Node *p=head;  //pointer that will iterate over the address stored of each set currently 
  tail->next=n; 
  tail=tail->next;
  return head;  // always go back to the head or start of the list
}
