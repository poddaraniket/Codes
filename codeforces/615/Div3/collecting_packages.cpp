#include<bits/stdc++.h>
using namespace std;
 
int main() {
 int t;
 cin>>t;
 while(t--)
  {
    int c=0,diff;
    string s="";
    int n,i,j,temp,tempa;
    cin>>n;
    int a[n][2];
    for(i=0;i<n;i++)
     {
       cin>>a[i][0]>>a[i][1];
     }
    for(i=0;i<n;i++)
     {
       for(j=i+1;j<n;j++)
        {
          if(a[i][0]>a[j][0])
           {
             if(a[i][1]<a[j][1])
               {
                 c=1;
                 break;
               }
             else
              {  
                temp=a[i][0];
                a[i][0]=a[j][0];
                a[j][0]=temp;
                tempa=a[i][1];
                a[i][1]=a[j][1];
                a[j][1]=tempa;
              }
           }
          else if(a[i][0]==a[j][0])
           {
             if(a[i][1]>a[j][1])
             {
              tempa=a[i][1];
              a[i][1]=a[j][1];
              a[j][1]=tempa;
             }
           }
          else 
            {
              if(a[i][1]>a[j][1])
               {
                 c=1;
                 break;
               }
            }  
        }
       if(c==1)
        {
          break;
        } 
     }
    // for(i=0;i<n;i++)
    //  cout<<a[i][0]<<" "<<a[i][1]<<endl; 
    if(c==0)
    { 
    //cout<<"*"<<endl;  
    diff=a[0][0]-0;
    for(i=0;i<diff;i++)
      {
        s+='R';
      }
    diff=a[0][1]-0;
    for(i=0;i<diff;i++)
      {
        s+='U';
      }  
    for(i=0;i<n-1;i++)
     {
       //cout<<"**"<<endl;
       if(a[i][0]<a[i+1][0])
        {
          diff=a[i+1][0]-a[i][0];
          for(j=0;j<diff;j++)
            s+='R';
          diff=a[i+1][1]-a[i][1];
          for(j=0;j<diff;j++)
           s+='U';   
        }
      else
        {
          diff=a[i+1][1]-a[i][1];
          for(j=0;j<diff;j++)
           s+='U';
        }  
     }
    cout<<"YES"<<endl;
    cout<<s<<endl; 
    }
   else
     cout<<"NO"<<endl;     
  }
}