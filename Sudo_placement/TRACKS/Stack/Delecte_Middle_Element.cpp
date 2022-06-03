#include<bits/stdc++.h>
using namespace std;

stack<int> deleteMid(stack<int>s,int sizeOfStack,int current);

int main() {
    int testcases;
    cin>>testcases;
    
    while(testcases--)
    {
        int sizeOfStack;
        cin>>sizeOfStack;
        
        stack<int> myStack;
        
        for(int i=0;i<sizeOfStack;i++)
        {
            int x;
            cin>>x;
            myStack.push(x);
            
            
        }
        if(sizeOfStack==1)
        {
            cout<<myStack.top();
        }
        else
        {
        
            stack<int> modified=deleteMid(myStack,myStack.size(),0);
            
            
            while(!modified.empty())
            {
                cout<<modified.top()<<" ";
                modified.pop();
            }
        }
        cout<<endl;
        
    }   
	return 0;
}// } Driver Code Ends


//User function Template for C++

//You need to complete this function
stack<int> deleteMid(stack<int>s,int sizeOfStack,int current)
{
    //Your code here
    if(s.size()==1)
     {
        return s; 
     }
    int k=s.size()-ceil(s.size()/2.0); 
    stack<int> p;
    while(k--)
    {
       //int temp=s.top();
       p.push(s.top());
       s.pop();
    }
    s.pop();
    while(!p.empty())
     {
        s.push(p.top());
        p.pop();
     }
    return s; 
}

