#include<bits/stdc++.h>

using namespace std;

int modular(long long int a,long long int b,long long int c)
{
   if(b==2)
    return (a*a)%c;    
   if(b%2!=0)
    return (a*modular(a,b-1,c))%c; 
   else
    return (modular(a,b/2,c)*modular(a,b/2,c))%c;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int a,b,c;
        cin>>a>>b>>c;
        cout<<modular(a,b,c)<<endl;
    }
}