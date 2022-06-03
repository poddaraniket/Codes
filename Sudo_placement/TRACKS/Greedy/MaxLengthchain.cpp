#include <bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;
};



int maxChainLen(struct val p[],int n);
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		
		cout<<maxChainLen(p,n)<<endl;
	}
	return 0;
}// } Driver Code Ends
/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

bool my_fun(val a,val b){
    if(a.second == b.second) return a.first<b.first;
    return a.second<b.second;
}

/*You are required to complete this method*/
int maxChainLen(struct val p[],int n)
{
//Your code here
   //sort(p.begin(),p.end());
   int i, j;  
    int mcl[n];  
   sort(p,p+n,my_fun);
    /* Initialize MCL (max chain length) 
    values for all indexes */
    for ( i = 0; i < n; i++ )  
        mcl[i] = 1;  
      
    /* Compute optimized chain length values in bottom up manner */
    for ( i = 1; i < n; i++ )
      {
        for ( j = 0; j < i; j++ ) 
          {
            if ( p[i].first > p[j].second && mcl[i] < mcl[j] + 1)  
                mcl[i] = mcl[j] + 1;
          }
         //cout<<mcl[i]<<" "; 
      }
    //  for ( i = 0; i < n; i++ )  
    //     cout<<mcl[i]<<" ";
    //cout<<endl;        
    //cout<<mcl[n-1]<<endl;  
    // mcl[i] now stores the maximum chain length ending with Pair i  
      
    /* Pick maximum of all MCL values */
    // for ( i = 0; i < n; i++ )  
    //     if ( max < mcl[i] )  
    //         max = mcl[i];  
      
    /* Free memory to avoid memory leak */
    int maxi=0;
    for(i=0;i<n;i++)
     maxi=max(maxi,mcl[i]);
    return maxi;  
}