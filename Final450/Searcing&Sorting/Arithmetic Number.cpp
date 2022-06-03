int inSequence(int A, int B, int C){
        // code here
        if(C==0)
        {
          if(A==B)
            return true;
          else 
            return false;     
        }
        long long int vl=(long long int)B-(long long int)A+(long long int)C;
        //cout<<vl<<endl;
        double ans=(double)vl/(double)C;
        if(ceil(ans)==floor(ans) && ans>0)
         return 1;
        return 0; 
    }