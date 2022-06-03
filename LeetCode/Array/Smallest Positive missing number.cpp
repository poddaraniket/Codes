int missingNumber(int arr[], int n) 
    { 
        // Your code here
        bool exist=false;
        // check if one exists
        for(int i=0;i<n;i++)
         {
            if(arr[i]==1){
             exist=true;
             break;
            }
         }
        if(!exist)
         return 1;
        //convert all negs,zeros and value>n to 1 
        for(int i=0;i<n;i++)
         {
             if(arr[i]<=0 || arr[i]>n)
              arr[i]=1;
         }
        // now check which number is absent 
        for(int i=0;i<n;i++)
         {
            if(arr[abs(arr[i])-1]>0) 
                arr[abs(arr[i])-1]=arr[abs(arr[i])-1]*-1; 
         }
        for(int i=0;i<n;i++)
         {
             if(arr[i]>0)
              return i+1;
         }
        return n+1; 
    }