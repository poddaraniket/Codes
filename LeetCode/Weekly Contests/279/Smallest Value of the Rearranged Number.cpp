//O(|num|)

class Solution {
public:
    
    static bool cmp(char a,char b){
        return a>b;
    }
    
    long long smallestNumber(long long num) {
        bool isNeg=false;
        if(num<0)
        {
            num*=-1;
            isNeg=true;
        }
        string t;
        string s=to_string(num);
        if(isNeg){
            sort(s.begin(),s.end(),cmp);
            t='-'+s;
        }
        else{
            sort(s.begin(),s.end());
            int end=0,i=0;
            for(i=0;i<s.length();i++){
                if(s[i]!='0')
                    break;
                end++;
            }
            if(i>=s.length())
                return stoll(s);
            t=s[i]+s.substr(0,end)+s.substr(i+1);
        }
        
        
        
        return stoll(t);
    }
};