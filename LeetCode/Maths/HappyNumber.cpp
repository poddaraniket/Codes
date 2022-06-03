class Solution {
public:
    map<int,bool> mp;
    int sum(int n)
    {
        int num=0;
        while(n)
        {
            int mod=n%10;
            num+=(mod*mod);
            n/=10;
        }
        return num;
    }
    
    bool isHappy(int n) {
        mp[n]=true;
        while(n!=1)
        {
            if(n<10)
            {
                if(n==7)
                    return true;
                return false;
            }
            n=sum(n);
            //cout<<n<<endl;
            if(mp[n]==true)
               return false;  
            mp[n]=true;
        }
        return true;
    }
};