vector<vector<int>> res;
    
    void combinationSumUtil(vector<int> &A, int index,int B,vector<int> &V){
        if(B==0)
         {
             res.push_back(V);
             return;
         }
        else if(B<0)
         return;
        for(int i=index;i<A.size();i++)
         {
            V.push_back(A[i]); 
            combinationSumUtil(A,i,B-A[i],V);
            V.pop_back(); // Backtrack
         }
    }
    
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        // Your code 
        vector<int> v;
        set<int> s;
        for(int i=0;i<A.size();i++){
            s.insert(A[i]);
        }
        vector<int> updated;
        set<int>::iterator itr;
        for (itr = s.begin(); itr != s.end(); itr++)
        {
            updated.push_back(*itr);
        }
        combinationSumUtil(updated,0,B,v);
        return res;
    }