#include <bits/stdc++.h>
using namespace std;

int s=0;

int permute(string a,int l,int r)
{
    if(l==r)
     {
        if(stoi(a)%8==0) 
         s++;
        //cout<<s<<endl; 
     }
    else
    {
    for(int i=l;i<=r;i++)
     {
         swap(a[l],a[i]);
         permute(a,l+1,r);
         swap(a[l],a[i]);
     }
    }
   //cout<<s<<endl;    
   return s;    
}

int main() {
    //code
    int t;
    cin>>t;
    while(t--)
    {
       s=0; 
       string n;
       cin>>n;
       int count=permute(n,0,n.size()-1);
       if(count>=1)
        cout<<"Yes"<<endl;
       else
        cout<<"No"<<endl;
        //cout<<cont<<endl;
    }
    return 0;
}