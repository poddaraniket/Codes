// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

Node* mergeKLists(Node* arr[], int N);

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout<<endl;
}

// Driver program to test above functions
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
	   int N;
	   cin>>N;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n;
           cin>>n;

           int x;
           cin>>x;
           arr[j]=new Node(x);
           Node *curr = arr[j];
           n--;

           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = new Node(x);
               curr->next =temp;
               curr=temp;
           }
   		}

   		Node *res = mergeKLists(arr,N);
		printList(res);

   }

	return 0;
}
// } Driver Code Ends


/*Linked list Node structure

struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/ 

/* arr[] is an array of pointers to heads of linked lists
  and N is size of arr[]  */
Node *merge(Node *a,Node *b)
{
    if(a==NULL)
     return b;
    if(b==NULL)
     return a;
    Node *start=NULL, *end=NULL;   // you will merge all lists in a one new list 
    if(a->data<=b->data)
     {
        start=a;
        end=start;
        a=a->next;
     }
    else
     {
        start=b;
        end=start;
        b=b->next; 
     }
    while(a&&b)
     {
        if(a->data>b->data)
         {
            end->next=b;
            end=end->next;
            b=b->next;
         }
        else
         {
            end->next=a;
            end=end->next;
            a=a->next;
         }
     }
    if(a)
     {
        end->next=a; 
     }
    if(b)
     {
         end->next=b;
     }
    return start; 
}
  
Node * mergeKLists(Node *arr[], int N)
{
       // Your code here
    //int c=0;
    Node *temp=NULL;
    for(int i=0;i<N;i++)
    {
        temp=merge(temp,arr[i]);
    }
    return temp;
}

