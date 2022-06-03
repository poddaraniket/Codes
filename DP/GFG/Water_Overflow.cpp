#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int t;
    cin>>t;
    while(t--)
     {
      int k,row,gls,s,i=2,d=2;
      cin>>k>>row>>gls;
      double temp;
      if(row>2)
       s=(((row-1)*row)/2)+gls;
      else
        s=1+(row-1)*gls;
      //cout<<s<<endl;    
      double dp[s+1]={0.0};
      dp[0]=0;
      dp[1]=k;
      if(dp[1]>1)
       {
           temp=(dp[1]-1)/2.0;
           dp[2]=temp;
           dp[3]=temp;
           dp[1]=1;
       }
      if(s>3)
      {
      for(d=2;d<row;d++)
       {
          int t=(d*(2+(d-1)))/2; 
          for(;i<=min(t,s);i++)
           {
              if(i+d<=s)
               {
                 if(dp[i]>1)
                  {
                    temp=(dp[i]-1)/2.0;
                    dp[i+d]+=temp;
                    if(i+d+1<=s)
                     dp[i+d+1]+=temp;
                    dp[i]=1;
                  }
               }
           }
       }
      }
    //   for(i=0;i<=s;i++)
    //   cout<<dp[i]<<" ";
    //   cout<<endl; 
      if(dp[s]>1)
       cout<<"1"<<endl;
      else
       cout<<dp[s]<<endl;
     }
}