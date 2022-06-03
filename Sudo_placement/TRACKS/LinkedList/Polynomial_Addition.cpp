#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int coeff;
    int pow;
    struct Node* next;
    
    Node(int c, int p){
        coeff = c;
        pow = p;
        next = NULL;
    }
    
};


void append(struct Node** head_ref, struct Node **tail_ref,
            int new_data, int new_data1)
{
    struct Node* new_node = new Node(new_data, new_data1);
    
    if (*head_ref == NULL)
        *head_ref = new_node;
    else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

void printList(struct Node *head)
{
    struct Node *temp = head;
    
    while (temp != NULL)
    {
       printf("%d %d ", temp->coeff, temp->pow);
       temp  = temp->next;
    }
}

void addPolynomial(Node *p1, Node *p2);


void create_node(int x, int y, struct Node **temp)
{
    struct Node *r, *z;
    z = *temp;
    if(z == NULL)
    {
        r = new Node(x, y);
        *temp = r;
        r->next = NULL;
    }
    else
    {
        r->next = new Node(x, y);
        r = r->next;
        r->next = NULL;
    }
}
 

/* Driver program to test above function*/
int main()
{
    
    int t;
    cin>>t;
    while(t--)
    {
        struct Node *poly1 = NULL, *poly2 = NULL, *poly = NULL;
        struct Node *tail1  = NULL,*tail2 = NULL;
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int x,y;
            cin>>x>>y;
            	append(&poly1,&tail1,x,y);
        }
        
         int m;
        cin>>m;
        for(int i=0;i<m;i++)
        {
            int x,y;
            cin>>x>>y;
            	append(&poly2,&tail2,x,y);
        }
        
        addPolynomial(poly1,poly2);
        
        cout<<endl;
       
    }

}
// } Driver Code Ends


/* Structure of Node used
struct Node
{
    int coeff;
    int pow;
    struct Node* next;
    
    Node(int c, int p){
        coeff = c;
        pow = p;
        next = NULL;
    }
    
};
*/

/* The below method print the required sum of polynomial
p1 and p2 as specified in output  */
void addPolynomial(Node *p1, Node *p2)
{
    //Your code here
    //Node *head2=NULL;
    //Node *curr;
    Node *pol1=p1,*pol2=p2;
    while(pol1 && pol2)
     {
        if(pol1->pow==pol2->pow)
         {
            cout<<(pol1->coeff)+(pol2->coeff)<<"x^"<<pol1->pow;
            pol1=pol1->next;
            pol2=pol2->next;
         }
        else if(pol1->pow>pol2->pow)
         {
            cout<<pol1->coeff<<"x^"<<pol1->pow; 
            pol1=pol1->next;
         }
        else if(pol1->pow<pol2->pow)
         {
            cout<<pol2->coeff<<"x^"<<pol2->pow; 
            pol2=pol2->next; 
         }
        if(pol1!=NULL || pol2!=NULL)
         cout<<" + ";
     }
    while(pol1)
     {
        cout<<pol1->coeff<<"x^"<<pol1->pow;
        pol1=pol1->next;
        if(pol1!=NULL)
         cout<<" + ";
     }
    while(pol2)
     {
        cout<<pol2->coeff<<"x^"<<pol2->pow;
        pol2=pol2->next;
        if(pol2!=NULL)
         cout<<" + ";
     }
    //return head2; 
}
