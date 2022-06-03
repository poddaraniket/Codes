int CountWays(string str){
		    // Code here
    if(str[0]=='0')
     return 0;
    int n=str.length();
    int dp[n]={0};
    dp[0]=1;
    for(int i=1;i<n;i++)
     {
         if(str[i]=='0' && str[i-1]=='0')
           dp[i]=0;
         // cannot include both together [03]     
         else if(str[i]!='0' && str[i-1]=='0')
          {
              dp[i]=dp[i-1];
              dp[i]%=1000000007;
          }
         // have to include both together [20]     
         else if(str[i]=='0' && str[i-1]!='0')
          {
              if(str[i-1]=='1' || str[i-1]=='2')  // 30
                dp[i]=(i>=2?dp[i-2]:1); 
              else
                dp[i]=0;
              dp[i]%=1000000007;
          }
         else
          {
              if(stoi(str.substr(i-1,2))<27)
               dp[i]=dp[i-1]+(i>=2?dp[i-2]:1);
              else 
               dp[i]=dp[i-1]; 
              dp[i]%=1000000007; 
          }
     }
     return dp[n-1];
}
