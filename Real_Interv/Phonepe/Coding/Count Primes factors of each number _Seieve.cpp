//O(NLogN)

#include <bits/stdc++.h>
using namespace std;

int prime[100001];
int factorial[6][100001];


void sieve()
{
    //(NlogN)
    for(int p=2;p<=100000;p++)
     {
        if(prime[p]==0)
         {
            for(int i=p;i<=100000;i+=p)
             {
                prime[i]++; 
             }
         }
     }
    //O(N) 
    for(int i=2;i<=100000;i++)
     {
        if(prime[i]<=5)
         factorial[prime[i]][i]=1;
     }
    //O(k*N) 
    for(int i=1;i<=5;i++)
     {
         for(int j=2;j<=100000;j++)
          factorial[i][j]+=factorial[i][j-1];
     }
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	int a,b,k;
	sieve();
	while(t--)
	 {
	     cin>>a>>b>>k;
	     cout<<factorial[k][b]-factorial[k][a-1]<<endl;
	 }
	return 0;
}
