#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	 {
	     cin>>arr[i];
	 }
	int dp[n]={0};
	int ma=arr[n-1];
	int mi=arr[0];
	
	//You are allowed to sell and then buy on the same day
	
	// Finding max profit from the transaction from i to n-1th day -> transaction2
	for(int i=n-2;i>=0;i--){
	    dp[i]=max(dp[i+1],ma-arr[i]);
	}
	
	// Finding max profit from the transaction from 0 to ith day -> transaction1
		for(int i=1;i<n;i++){
	    dp[i]=max(dp[i-1],dp[i]+(arr[i]-mi)); //summ ing up the profit from 0 to ith day and ith day to n-1(dp[i)
	}
	cout<<dp[n-1]<<endl;
	
	
	return 0;
}
