#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

void printMat(int M[MAX][MAX],int row,int col);

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
    	int n,m;
    	cin>>n>>m;
    	int a[MAX][MAX];
    	for(int i=0;i<n;i++)
    	for(int j=0;j<m;j++)
    	cin>>a[i][j];
    	printMat(a,n,m);
    	cout<<endl;
    }
}
// } Driver Code Ends


/*You are required to complete this function*/

void printMat(int M[MAX][MAX],int row,int col)
{
//Your code here 
  unordered_map<long long int,int> mp;
  vector<int> v;
  for(int i=0;i<row;i++)
   {
       long long int s=0;
       for(int j=0;j<col;j++)
        {
          s+=(M[i][j]*pow(2,j));
        }
       if(mp.find(s)==mp.end())
        mp[s]=i;
   }
  for(auto it=mp.begin();it!=mp.end();it++)
   {
     v.push_back(it->second);  
   }
  sort(v.begin(),v.end()); 
  for(int i=0;i<v.size();i++)
  {
    for(int j=0;j<col;j++)
     {
        cout<<M[v[i]][j]<<" "; 
     }
    cout<<"$"; 
  }
}