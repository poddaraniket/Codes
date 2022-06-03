
 bool isValid(int arr[],long long mid,int n,int k)
    {
        int painter=1,sum=0;
        for(int i=0;i<n;i++)
         {
             if(sum+arr[i]<=mid)
              {
                  sum+=arr[i];
              }
             else
              {
                  ++painter;
                  sum=arr[i];
                  if(painter>k)
                   return false;
              }
         }
        return true; 
    }
    
    long long minTimeUtil(int arr[],long long start,long long end,int n,int k){
        long long best=end;
        while(start<=end){
            long long mid=(start+end)/2;
            if(isValid(arr,mid,n,k)){
                best=mid;
                end=mid-1;
            }else{
                start=mid+1; //min finding
            }
        }
        return best;
    }
    
    long long minTime(int arr[], int n, int k)
    {
        // code here
        // return minimum time
        long long start=0,end=0;
        for(int i=0;i<n;i++) 
         {
             start=max(start,(long long)arr[i]);
             end+=arr[i];
         }
        return minTimeUtil(arr,start,end,n,k); 
    }