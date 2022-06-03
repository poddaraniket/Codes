vector<int> factorial(int N){
        // code here
        vector<int>v;
        int temp=N;
        while(N){
            int t=N%10;
            v.insert(v.begin(),t);
            N/=10;
        }
        //cout<<v.size()<<endl;
        for(int i=temp-1;i>=2;i--)
        {
            int carry=0;
            for(int j=v.size()-1;j>=0;j--){
              //  cout<<v[j]<<endl;
                int val=(v[j]*i)+carry;
                v[j]=val%10;
                carry=val/10;
            }
            if(carry>0){
                while(carry){
                   int t=carry%10;
                   v.insert(v.begin(),t);
                   carry/=10; 
                }
            }
        }
        return v;
    }