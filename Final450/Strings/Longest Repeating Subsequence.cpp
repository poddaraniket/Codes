//O(N^2)

//Same as LCS just that here two strings are just duplicate and we have to make sure common character should be of same index

int LongestRepeatingSubsequence(string str){
		    int l=str.length();
		    int dp[l+1][l+1];
		    for(int i=0;i<=l;i++){
		        dp[i][0]=0;
		        dp[0][i]=0;
		    }
		    for(int i=1;i<=l;i++){
		        for(int j=1;j<=l;j++){
		            if(str[i-1]==str[j-1] && i!=j){
		                dp[i][j]=dp[i-1][j-1]+1;
		            }
		            else{
		                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		            }
		        }
		    }
		  // for(int i=1;i<=l;i++) {
		  //     for(int j=)
		  // }
		   return dp[l][l]; 
		}