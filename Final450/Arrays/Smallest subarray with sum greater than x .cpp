int sb(int arr[], int n, int x)
    {
        // Your code goes here   
        int low=0,sum=0,mindiff=n;
        for(int high=0;high<n;high++)
         {
            sum+=arr[high];
            while(sum>x)
            {
                sum-=arr[low];
                mindiff=min(mindiff,high-low+1);
                low++;
            }
         }
         return mindiff;
    }