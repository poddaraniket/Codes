class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> v;
        int n=digits.size();
        int carry=0,sum=0;
        for(int i=n-1;i>=0;i--){
           sum=carry+digits[i];
           if(i==n-1)
              sum++;  
           v.push_back(sum%10);
           carry=sum/10; 
        }
        if(carry>0)
          v.push_back(carry);
        reverse(v.begin(),v.end());
        return v;
    }
};