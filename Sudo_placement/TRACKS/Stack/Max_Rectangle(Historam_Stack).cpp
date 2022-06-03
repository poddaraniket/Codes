#include<bits/stdc++.h>

using namespace std;

#define MAX 1001
int maxi=0;

void maxA(int t[],int m)
{
    int te,temp,i;
    stack<int> s;
    for(i=0;i<m;)
    {
        if(s.empty() || t[i]>=t[s.top()])
          s.push(i++);
        else 
         {
            temp=s.top();
            s.pop();
            if(s.empty())
             {
                te=t[temp]*i; 
             }
            else 
              te=t[temp]*(i-s.top()-1);       
            maxi=max(te,maxi);
            //cout<<te<<" ";
            //s.pop();
         }
    }
    while(!s.empty())
    {
        int temp=s.top();
        s.pop();
        if(s.empty())
         te=t[temp]*i;
        else
         te=t[temp]*(i-s.top()-1);
        maxi=max(te,maxi); 
    }
}

int maxArea(int M[MAX][MAX],int n,int m)
{
    int i=0,j;
    int tmp[m]={0};
    //int maxi=0;
    while(i<n)
    {
        int mini=100000,c=0;
        for(j=0;j<m;j++)
        {
         if(M[i][j]==0)
          tmp[j]=0;
         else 
          tmp[j]+=M[i][j];
        }
       maxA(tmp,m);
       i++;
    }
   return maxi;
}

int main()
{
    int t;
    cin>>t;
    int M[MAX][MAX];
    while(t--)
    {
     maxi=0;    
     int m,n;
     cin>>n>>m;
     //int M[n][m];
     for(int i=0;i<n;i++)
      {
        for(int j=0;j<m;j++)
         cin>>M[i][j];
      }
    //  for(int i=0;i<n;i++)
    //   {
    //     for(int j=0;j<m;j++)
    //      cout<<M[i][j]<<" ";
    //     cout<<endl; 
    //   } 
     cout<<maxArea(M,n,m)<<endl; 
    }
}