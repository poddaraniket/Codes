#include <bits/stdc++.h>
using namespace std;

#define SIZE 5

int input[SIZE];
int front=-1,rear=-1;

void enQueue(int x){
    //cout<<"-"<<rear<<endl;
    if(rear==SIZE-1 && front==0 || rear==(front-1)%(SIZE-1))
    {
     cout<<"Queue is Full"<<endl;
     return;
    }
    else if(front==-1)
    {
        front=0;
        rear=0;
        input[rear]=x;
    }
    else if(rear==SIZE-1 && front!=0){
        rear=0;
        input[rear]=x;
    }
    else{
        rear++;
       // cout<<"*"<<x<<" "<<rear<<endl;
        input[rear]=x;
    }
}

int deQueue(){
    if(front==-1)
    {
     cout<<"Queue is Empty"<<endl;
     return INT_MIN;
    }
    int data=input[front];
    input[front]=-1;
    if(front==rear)
     {
        front=-1;
        rear=-1;
     }
    else if(front==SIZE-1){
        front=0;
    } 
    else
     {
         front++;
     }
    return data;
}

void displayQueue(){
    if(front==-1)
    {
        cout<<"Queue is Empty"<<endl;
        return;
    }
   // cout<<front<<" "<<rear<<endl;
    if(rear>=front)
     {
        for(int i=front;i<=rear;i++)
         {
             cout<<input[i]<<" ";
         }
        cout<<endl; 
     }
    else{
        for(int i=front;i<SIZE;i++)
         {
            cout<<input[i]<<" ";
         }
        for(int i=0;i<=rear;i++)
         {
            cout<<input[i]<<" ";
         }
        cout<<endl; 
    } 
}

int main() {
    
    enQueue(14);
    enQueue(22);
    enQueue(13);
    enQueue(-6);
 
    // Display elements present in Circular Queue
    displayQueue();
 
    // Deleting elements from Circular Queue
    cout<<"Deleted value = "<<deQueue()<<endl;
    cout<<"Deleted value = "<<deQueue()<<endl;
 
    displayQueue();
 
    enQueue(9);
    enQueue(20);
    enQueue(5);
 
    displayQueue();
 
    enQueue(20);
    
	return 0;
}
