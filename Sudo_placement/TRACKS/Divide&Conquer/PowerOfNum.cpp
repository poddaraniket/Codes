#include<bits/stdc++.h>

using namespace std;

#define MAX 1000000007 

long long modular(int a,int b)
{
   if(b==2)
    return (a*a)%MAX;    
   if(b%2!=0)
    return (a*modular(a,b-1))%MAX; 
   else
    return (modular(a,b/2)*modular(a,b/2))%MAX;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,temp,r=0,mod;
        cin>>n;
        temp=n;
        while(temp)
        {
            mod=temp%10;
            r=(r*10)+mod;
            temp/=10;
        }
        //cout<<"*"<<r<<endl;
        cout<<modular(n,r)<<endl;
    }
}