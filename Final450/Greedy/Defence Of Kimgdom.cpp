#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

int maxAreaTillRow(int arr[],int n)
    {
        int left[n];
        stack<int> s,s1;
        for(int i=0;i<n;i++)
         {
             if(s.empty())
              {
                  left[i]=0;
                  s.push(i);
              }
             else
             {
                 while(!s.empty() && arr[s.top()]>=arr[i])
                  {
                        s.pop();
                  }
                 left[i]=s.empty()?0:s.top()+1;
                 s.push(i);
             }
         }
        int right[n];
        for(int i=n-1;i>=0;i--)
         {
             if(s1.empty())
              {
                  right[i]=n-1;
                  s1.push(i);
              }
             else
             {
                 while(!s1.empty() && arr[s1.top()]>=arr[i])
                  {
                        s1.pop();
                  }
                 right[i]=s1.empty()?n-1:s1.top()-1;
                 s1.push(i);
             }
         }
        // for(int i=0;i<n;i++)
        //  cout<<left[i]<<" ";
        // cout<<endl;
        // for(int i=0;i<n;i++)
        //  cout<<right[i]<<" ";
        // cout<<endl;
        int maxi=-1; 
        for(int i=0;i<n;i++)
         {
             
             maxi=max(maxi,arr[i]*(right[i]-left[i]+1));
         }
        return maxi;
    }
  
    int maxArea(int mat[MAX][MAX], int n, int m) {
        // Your code here
        int maxi=-1;
        int ht[m]={0};
        for(int i=0;i<n;i++)
         {
             for(int j=0;j<m;j++)
               ht[j]=mat[i][j]==0?0:ht[j]+1;
             maxi=max(maxi,maxAreaTillRow(ht,m));  
         }
        return maxi; 
    }

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	 {
	     int col,row,num;
	     cin>>row>>col>>num;
	     int mat[MAX][MAX];
	     memset(mat,1,sizeof(mat));
	     vector<int> r(num),c(num);
	     for(int i=0;i<num;i++)
	      {
	          int x,y;
	          cin>>x>>y;
	          r[i]=x;
	          c[i]=y;
	      }
	     for(int i=0;i<num;i++)
	      {
	          for(int j=0;j<col;j++)
	           {
	               mat[r[i]-1][j]=0;
	           }
	      }
	     for(int i=0;i<num;i++)
	      {
	          for(int j=0;j<row;j++)
	           {
	               mat[j][c[i]-1]=0;
	           }
	      }
	     cout<<maxArea(mat,row,col)<<endl; 
	 }
	return 0;
}
