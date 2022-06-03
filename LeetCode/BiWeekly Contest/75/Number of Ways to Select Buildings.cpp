//O(N)

class Solution {
public:
    long long numberOfWays(string s) {
        int len=s.length();
        vector<int> freqZeroL(len,0),freqZeroR(len,0),freqOneL(len,0),freqOneR(len,0);
        
        //Left-----------------------------
        
        if(s[0]=='0'){
            freqZeroL[0]=1;
        }else{
             freqOneL[0]=1;
        }
        
        for(int i=1;i<len;i++){
            if(s[i]=='0'){
                freqZeroL[i]=freqZeroL[i-1]+1;
                freqOneL[i]=freqOneL[i-1];
            }
            else{
                freqOneL[i]=freqOneL[i-1]+1;
                freqZeroL[i]=freqZeroL[i-1];
            }
        }
        
        // Right ----------------------------------
        
        if(s[len-1]=='0'){
            freqZeroR[len-1]=1;
        }else{
             freqOneR[len-1]=1;
        }
        for(int i=len-2;i>=0;i--){
            if(s[i]=='0'){
                freqZeroR[i]=freqZeroR[i+1]+1;
                freqOneR[i]=freqOneR[i+1];
            }
            else{
                freqOneR[i]=freqOneR[i+1]+1;
                freqZeroR[i]=freqZeroR[i+1];
            }
        }
        long long sum=0;
        for(int i=1;i<len-1;i++){
            if(s[i]=='1'){
                 sum+=freqZeroL[i]*freqZeroR[i]; 
            }
            else{
                  sum+=freqOneL[i]*freqOneR[i];
            }
        }
       return sum; 
    }
};