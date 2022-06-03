
#include<bits/stdc++.h>
using namespace std;
#define ll long long
queue<ll> modifyQueue(queue<ll> q, int k);
int main(){
    ll t;
    cin>>t;
    while(t-->0){
        ll n,k;
        cin>>n>>k;
        queue<ll> q;
        while(n-->0){
            ll a;
            cin>>a;
            q.push(a);
        }
        queue<ll> ans=modifyQueue(q,k);
        while(!ans.empty()){
            int a=ans.front();
            ans.pop();
            cout<<a<<" ";
        }
        cout<<endl;
    }
}// } Driver Code Ends


//User function Template for C++

queue<ll> modifyQueue(queue<ll> q, int k)
{
    //add code here.
    int c=0;
    stack<ll> s;
    queue<ll> qi;
    while(!q.empty())
    {
      ++c;
      if(c>k)
       {
          qi.push(q.front());
          q.pop();
       }
      else
       {
           s.push(q.front());
           q.pop();
       }
    } 
    while(!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
    while(!qi.empty())
    {
        q.push(qi.front());
        qi.pop();
    }
    return q;
}