long long int maximizeSum(long long int a[], int n, int k)
    {
        // Your code goes here
        sort(a,a+n);
        long long int sum=0;
        int i=0;
        while(k)
         {
             if(a[i]<=0){
                 k--;
                 a[i]=a[i]*-1;
             }
             else
              break;
            i++; 
         }
        //cout<<k<<endl; 
        if(k%2!=0){
            a[min(n-1,i)]=a[min(n-1,i)] * -1;
        }
        for(i=0;i<n;i++){
       // cout<<a[i]<<" ";
         sum+=a[i];
        }
       // cout<<endl;
        return sum; 
    }