class Solution {
public:
    int dp[1002][1002];
    
    int min(int a,int b){
        if(a<b)
            return a;
        return b;
    }
    
    int count(string &floor, int numCarpets, int carpetLen,vector<int> &v,int index){
        if(numCarpets==0 || index>=floor.length()){
            return 0;
        }
        if(dp[index][numCarpets]!=-1)
            return dp[index][numCarpets];
        if(floor[index]=='0')
             dp[index][numCarpets]=count(floor,numCarpets,carpetLen,v,index+1);
        int x=min(index+carpetLen,floor.length())-1;
        int numofWhites=v[x];
        if(index!=0)
          numofWhites-=v[index-1];
        int ans1=numofWhites+count(floor,numCarpets-1,carpetLen,v,index+carpetLen);
        int ans2=count(floor,numCarpets,carpetLen,v,index+1);
        // cout<<ans1<<" "<<ans2<<endl;
        dp[index][numCarpets]=max(ans1,ans2);
        return dp[index][numCarpets];
    }
    
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        for(int i=0;i<=floor.length();i++){
            for(int j=0;j<=numCarpets;j++){
                dp[i][j]=-1;
            }
        }
       vector<int> v;
       int total=0,maxi=0; 
       for(int i=0;i<floor.length();i++){
          if(floor[i]=='1')
              total++;
          v.push_back(total); 
       }
        if(v[floor.length()-1]==0)
            return 0;
        // for(int i=0;i<floor.length();i++){
        //     cout<<v[i]<<" ";
        // }
        // cout<<endl;
        int whitesRemoved=count(floor,numCarpets,carpetLen,v,0); 
        // cout<<whitesRemoved<<endl;
        return total-whitesRemoved;
    }
};