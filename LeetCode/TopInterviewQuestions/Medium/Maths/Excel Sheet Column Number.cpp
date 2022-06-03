//O(N)

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int len=columnTitle.length();
        // long long int value=26*(len-1);
        long long int sum=0;
        // cout<<value<<endl;
        for(int i=0;i<len;i++){
            int d=columnTitle[i]-'A' + 1;
            sum= 26 * sum + d;
        }
        return (int)sum;
    }
};