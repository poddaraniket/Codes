 bool find3Numbers(int A[], int n, int X)
    {
        //Your Code Here
        sort(A,A+n);
        for(int i=0;i<n-2;i++){
            int l=i+1,h=n-1;
            while(l<h)
            {
                if(A[i]+A[l]+A[h]>X)
                 h--;
                else if(A[i]+A[l]+A[h]<X)
                 l++;
                else{
                   // cout<<A[i]<<" "<<A[l]<<" "<<h<<endl;
                    return true;   
                }
          }
        }
        return false;
    }