int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> s;
        for(int i=0;i<n;i++)
         {
            s.push(i); 
         }
        while(s.size()>1){
            int A=s.top();
            s.pop();
            int B=s.top();
            s.pop();
            if(M[A][B]==0){
                s.push(A);
            }else{
                s.push(B);
            }
        }
        if(s.empty())
            return -1;
        int C=s.top();
        s.pop();
        //cout<<C<<endl;
        for(int i=0;i<n;i++){
            if(i!=C && (M[i][C]==0 || M[C][i]==1))
             return -1;
        }
        return C;
    }