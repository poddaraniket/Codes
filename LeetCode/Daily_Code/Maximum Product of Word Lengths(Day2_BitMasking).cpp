//BitsMasking

class Solution {
public:
    
    static int max(int a,int b){
        if(a>b)
         return a;
        return b;
    }
    
    int maxProduct(vector<string>& words) {
      int n=words.size();
      int ans=0; 
      vector<int> masks(n,0);
        for(int i=0;i<words.size();i++){
            for(auto ch : words[i]){
                masks[i]|= 1 << (ch-'a');
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if((masks[i] & masks[j]) == 0)
                    ans= max(ans,words[i].length()*words[j].length());
            }
        }
        return ans;
    }
};