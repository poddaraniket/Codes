class ATM {
public:
    
    long long int v[5];
    int denom[5];
    ATM() {
        for(int i=0;i<5;i++){
            v[i]=0;
        }
        denom[0]=20;
        denom[1]=50;
        denom[2]=100;
        denom[3]=200;
        denom[4]=500;
    }
    
    void deposit(vector<int> banknotesCount) {
        for(int i=0;i<banknotesCount.size();i++){
            v[i]+=banknotesCount[i];
        }
    }
    
    vector<int> withdraw(int amount) {
        vector<int> ans(5);
        for(int i=4;i>=0;i--){
            if(amount>=denom[i]){
                int c=amount/denom[i];
                if(c>v[i]){
                    c=v[i];
                }
                v[i]-=c;
                amount-=(denom[i]*c);
                ans[i]+=c;
            }
        }
        if(amount==0){
            return ans;
        }else{
            for(int i=0;i<5;i++){
                v[i]+=ans[i];
            }
        }
        vector<int> error(1,-1);
        return error;
    }
};
