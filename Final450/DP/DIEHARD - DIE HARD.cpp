#include <bits/stdc++.h>
using namespace std;

int dp[10001][10001];

int solve(int h,int a,int i)
{
    if(h<=0 || a<=0)
     return 0;
    if(dp[h][a]!=-1)
     return dp[h][a];
    int x=0,y=0,z=0; // wen we don't check for x or y or z bcoz its already used then we need a default value to comp the max
    if(i!=1)
      x=1+solve(h+3,a+2,1);
    if(i!=2)
     y=1+solve(h-5,a-10,2);
    if(i!=3)
     z=1+solve(h-20,a+5,3);
    dp[h][a]=max(max(x,y),z); 
    return dp[h][a];
}


int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	 {
	     int h,a;
	     cin>>h>>a;
	     memset(dp,-1,sizeof(dp));
	     cout<<max(max(solve(h+3,a+2,1),solve(h-5,a-10,2)),solve(h-20,a+5,3))<<endl;
	 }
	return 0;
}
