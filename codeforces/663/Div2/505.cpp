

#include<bits/stdc++.h>
using namespace std;
 
int Matrix[4][500001];
 
string pos[]={"000","001","010","011","100","101","110","111"};
 
void fill(int n,int m)
{
    char c;
    for(int i=0;i<n;i++)
     {
        for(int j=0;j<m;j++)
         {
           cin>>c;  
           Matrix[i][j]=c-'0';
         }
     }
    // for(int i=0;i<n;i++)
    //  {
    //      for(int j=0;j<m;j++)
    //       {
    //           cout<<Matrix[i][j]<<" ";
    //       }
    //      cout<<endl; 
    //  }
}

// to check if the min of row or column is 2 so here u have odd parity and even parity in alternate for it to satisfy
// odd partiy=odd no. of 1's 
 
void check2(int n,int m)
{
    int p=0,c1=0,c2=0;
    int val[]={0,1};
    int parity[m],par1[m],par2[m];
    for(int i=0;i<m;i++)
     {
        par1[i]=val[i%2];
        par2[i]=par1[i]^1;
        //p++;
        int sum=Matrix[0][i]+Matrix[1][i];
        parity[i]=sum%2;
     }
    for(int i=0;i<m;i++)
     {
        if(par1[i]^parity[i]==1)
         c1++;
        if(par2[i]^parity[i]==1)
         c2++; 
     }
    cout<<min(c1,c2)<<endl; 
}

//here we have pair of parity for (1st two elements in col.) and (2nd and 3rd element in column)
//here pair should be adjacent
 
void check3(int n,int m)
{
    //cout<<"*"<<endl;
    //int size=sizeof(pos)/sizeof(pos[0]);
    int mini=1000000;
    pair<int,int> p;
    for(int i=0;i<8;i++)
     {
        int cost=0; 
        string s=pos[i];
        int a=s[0]-'0';
        int b=s[1]-'0';
        int c=s[2]-'0';
        //cout<<a<<" "<<b<<" "<<c<<" ";
        p.first=(a+b)%2;
        p.second=(b+c)%2;
        //cout<<p.first<<" "<<p.second<<" ";
        for(int j=0;j<m;j++)
         {
            if(j==0)
             {
                //cout<<Matrix[0][0]<<" "; 
                cost=abs(Matrix[0][0]-a)+abs(Matrix[1][0]-b)+abs(Matrix[2][0]-c);
                continue;
                //cout<<cost<<" ";
             }
            //pair<int,int> t;
            p.first=1^p.first;
            p.second=1^p.second;
            int x=(Matrix[0][j]+Matrix[1][j])%2;
            int y=(Matrix[1][j]+Matrix[2][j])%2;
            if(p.first!=x && p.second!=y)
             cost++;
            else
             {
                if(p.first!=x)
                 cost++;
                if(p.second!=y)
                 cost++;
             }
         }
        //cout<<cost<<endl; 
        mini=min(mini,cost); 
     }
    cout<<mini<<endl; 
}
 
int main()
{
    int n,m;
    cin>>n>>m;
    //any even length sq matrix geater than 2(eg 4,6..) will never have odd number of 1's bcoz its subset (eg 2 for 4 will have odd and 4*odd=even)
    //so any min of row or column has to be less than 4
    if(min(n,m)>3)
     cout<<"-1"<<endl;
    else if(min(n,m)==1)
     cout<<"0"<<endl;
    else if(min(n,m)==2)
     {
        fill(n,m); 
        check2(n,m); 
     }
    else 
     {
        fill(n,m); 
        check3(n,m);
     }
}