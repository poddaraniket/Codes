int checkMirrorTree(int n, int e, int A[], int B[]) {
        // code here
        map<int,stack<int>> mp;
        for(int i=0;i<2*e;i+=2)
         {
             mp[A[i]].push(A[i+1]);
         }
        for(int i=0;i<2*e;i+=2){
            if(mp[B[i]].top()!=B[i+1]){
                 //cout<<i<<endl;
                 //cout<<mp[A[i]].top()<<" "<<A[i+1]<<endl;
                 return 0;
            }
            
            else
             {
                 mp[B[i]].pop();
             }
        }
        return 1;
    }