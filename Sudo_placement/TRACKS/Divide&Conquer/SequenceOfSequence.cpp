#include<bits/stdc++.h>

using namespace std;

int sequence(int m,int n)
{
    if(m<n)
     return 0;
    if(n==0)
     return 1;
    return sequence(m/2,n-1)+sequence(m-1,n); 
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,i,j,k;
        cin>>m>>n;
        cout<<sequence(m,n)<<endl;
    }
}