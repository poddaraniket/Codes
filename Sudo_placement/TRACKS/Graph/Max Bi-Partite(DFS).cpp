#include <bits/stdc++.h>
using namespace std;
#define M 100
#define N 100
int maxBPM(bool bpGraph[M][N],int m,int n);
int main()
{
	int t;
	cin>>t;
	while(t--){
		int m,n;
		cin>>m>>n;		
		bool bpGraph[M][N];
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
				cin>>bpGraph[i][j];
		cout << maxBPM(bpGraph,m,n)<<endl;
	}
    return 0;
}// } Driver Code Ends


/*Complete the function below*/

bool bpm(bool bpGraph[M][N],int m,int n,bool seen[],int match[],int u)
{
    for(int v=0;v<n;v++)
     {
         if(bpGraph[u][v] && seen[v]!=true)
          {
             seen[v]=true;
             if(match[v]<0 || bpm(bpGraph,m,n,seen,match,match[v]))
             {
              match[v]=u; 
              return true;
             }
          }
     }
    return false; 
}

int maxBPM(bool bpGraph[M][N],int m,int n)
{
//add code here.
  int match[n];
  memset(match,-1,sizeof(match));
  bool seen[n];
  int result=0;
  for(int i=0;i<m;i++)
   {
       memset(seen,false,sizeof(seen));
       if(bpm(bpGraph,m,n,seen,match,i)) 
        result++;
   }
  return result; 
}