#include<bits/stdc++.h>

using namespace std;

#define MAXSIZE 101
stack<int> s;

void sort()
{
   stack<int> p;
   while(!s.empty())
    {
      int temp=s.top();
      s.pop();
      while(!p.empty() && p.top()>temp)
       {
           s.push(p.top());
           p.pop();
       }
      p.push(temp); 
    }
   p.swap(s);
}

void print()
{
   while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
   cout<<endl;    
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
     int n;
     cin>>n;
     for(int i=0;i<n;i++)
      {
        int num;  
        cin>>num;
        s.push(num);
      }
     sort();
     print();
    }
}