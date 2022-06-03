vector<int> canMakeTriangle(vector<int> A, int N){
        // code here
        int a=A[0];
        int b=A[1];
        int c;
        vector<int> v;
        for(int i=2;i<N;i++){
            c=A[i];
            if(a+b>c && a+c>b && b+c>a)
             v.push_back(1);
            else
             v.push_back(0);
            a=b;
            b=c;
        }
        return v;
    }