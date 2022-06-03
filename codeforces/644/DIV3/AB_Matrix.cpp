#include <bits/stdc++.h>
using namespace std;
 
void create(int n,int m,int a, int b)
{
    int temp=a;
    int arr[n][m];
    int i,j;
    //int store[m]={0};
    for(i=0;i<n;i++)
     {
         for(j=0;j<m;j++)
          arr[i][j]=0;
     }
    j=0; 
    for(i=0;i<n;i++)
     {
        temp=a; 
       // j=j%m;
        while(j<m)
         {
            j=j%m;
            //cout<<j<<endl;
            if(temp>0)
             {
                arr[i][j]=1; 
                //store[j]+=1;
                temp--;
             }
            else
             break;
            j++;
            j=j%m;
          }
     }
    for(i=0;i<n;i++)
     {
         for(j=0;j<m;j++)
          cout<<arr[i][j];
         cout<<endl; 
     }
}
 
int main() {
	// your code goes here
	
	int t;
	cin>>t;
	while(t--)
	{
	   int n,m,a,b;
	   cin>>n>>m>>a>>b;
	   if(n*a!=m*b)
	    {
	        cout<<"NO"<<endl;
	    }
	   else
	    {
	        cout<<"YES"<<endl;
	        create(n,m,a,b);
	    }
	}
  return 0;
}
