//O(Nlog(p))
class Solution {
public:
    
    long long int power(int p,int c,int modulo){
        if(c==0)
            return 1;
        if(c==1)
            return p%modulo;
        long long int ans=1;
        long long int known=power(p,c/2,modulo)%modulo;
        if(c%2){
            ans=(ans*p)%modulo;
        }
        return (ans * ((known*known)%modulo))%modulo;
    }
    
    string subStrHash(string s, int p, int modulo, int k, int hashValue) {
        int n=s.length();
        long long int sum=0;
        int c=k-1;
        for(int i=n-1;i>=n-k;i--){
           sum=(sum+((s[i]-'a'+1)*power(p,c,modulo))%modulo)%modulo;
           c--;
        }
        cout<<sum<<" ";
        string ans;
        for(int i=n-k-1;i>=0;i--){
            if(sum==hashValue){
                ans=s.substr(i+1,k);
            }
            sum=(sum+modulo-((s[i+k]-'a'+1)*power(p,k-1,modulo))%modulo)%modulo;
            sum=(sum*p)%modulo;
            sum=(sum+(s[i]-'a'+1))%modulo;
        }
        if(sum==hashValue){
          ans=s.substr(0,k);
        }
        return ans;
    }
};