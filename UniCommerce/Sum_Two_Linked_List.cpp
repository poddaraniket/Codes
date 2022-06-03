#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node (int data)
     {
        this->data=data;
        this->next=NULL;
     }
};

Node* convert(int n,Node *root)
{
    Node *curr=root;
    while(n)
     {
        int mod=n%10;
        Node *temp=new Node(mod);
        if(!root)
         {
            root=temp;
            //curr=curr->next;
         }
        else
         {
            curr->next=temp;
         }
        curr=temp; 
        //cout<<curr->data<<" "; 
        n/=10; 
     }
    //cout<<endl; 
    return root; 
}

Node* add(Node *first,Node *second,Node *result)
{
    int carry=0,sum;
    Node *curr=result;
    //cout<<first->data<<" "<<second->data<<endl;
    while(first!=NULL || second!=NULL)
     {
        if(first==NULL)
         sum=second->data+carry;
        else if(second==NULL)
         sum=first->data+carry;
        else 
         sum=(first->data)+(second->data)+carry;
        //cout<<sum<<endl; 
        int data=sum%10;
        carry=sum/10;
        //cout<<data<<endl;
        Node *temp=new Node(data);
        if(!result)
         result=temp;
        else
         {
            curr->next=temp;
         }
        curr=temp; 
        if(first)
          first=first->next;
        if(second)  
         second=second->next;
     }
    return result; 
}

void print(Node *root)
{
    //cout<<"*"<<endl;
    Node *temp=root;
    while(temp!=NULL)
     {
        //cout<<"/"<<endl; 
        cout<<temp->data<<" ";
        temp=temp->next;
     }
    cout<<endl; 
}

int main() {
	// your code goes here
	Node *first=NULL;
	Node* second=NULL;
	Node* result=NULL;
	int num1,num2;
	cin>>num1>>num2;
	first=convert(num1,first);
	//cout<<"*"<<endl;
	//print(first);
	second=convert(num2,second);
	//print(second);
	result=add(first,second,result);
	print(result);
	return 0;
}
