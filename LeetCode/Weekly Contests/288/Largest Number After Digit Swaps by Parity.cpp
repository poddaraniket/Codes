class Solution {
public:
    int largestInteger(int num) {
        priority_queue<int> odd,even;
        vector<char> parity;
        while(num){
            int d=num%10;
            if(d%2){
               odd.push(d);
               parity.push_back('o');
            }
            else{
                even.push(d);
                parity.push_back('e');
            }
            num/=10;
        }
       reverse(parity.begin(),parity.end());
       int sum=0;
       for(int i=0;i<parity.size();i++){
           sum*=10;
           if(parity[i]=='o'){
               sum+=odd.top();
               odd.pop();
           }else{
               sum+=even.top();
               even.pop();
           }
       }
       return sum; 
    }
};