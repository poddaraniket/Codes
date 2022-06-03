//O(N)

class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        long long a=0,b=0;
        if(pattern[0]==pattern[1]){
           for(int i=text.length()-1;i>=0;i--){
            if(pattern[0]==text[i])
                b++;
            }
           return (b*(b+1))/2; 
        } 
        long long count1=0,count2=0;
        // adding pattern[1]
        for(int i=text.length()-1;i>=0;i--){
            if(pattern[1]==text[i])
                b++;
            if(pattern[0]==text[i]){
                count1+=(b+1);
            }
        }
        // adding pattern[0]
        for(int i=0;i<text.length();i++){
            if(pattern[0]==text[i])
                a++;
            if(pattern[1]==text[i]){
                count2+=(a+1);
            }
        }
        // cout<<count1<<" "<<count2<<endl;
        return max(count1,count2);
    }
};