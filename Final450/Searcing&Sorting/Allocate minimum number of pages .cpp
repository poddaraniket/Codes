bool isValid(int arr[],long long int mid,int n,int stud){
        int count=1,sum=0;
        for(int i=0;i<n;i++)
          {
            if(sum+arr[i]<=mid)
             {
                sum+=arr[i]; 
             }
            else
             {
                ++count; 
                sum=arr[i];
                if(count>stud)
                    return false; 
             }
          }
        return true;  
    }
    
    int findPagesUtil(int arr[],long long int start,long long int end,int stud,int n){
        long long int best=0;
        while(start<=end){
            long long int mid=(start+end)/2;
            if(isValid(arr,mid,n,stud))
            {
                best=mid;
                end=mid-1;
            }
            else 
             {
                start=mid+1;
             }
        }
        return best;
    }
    
    int findPages(int arr[], int n, int m) 
    {
        //code here
        int start=0,end=0;
        for(int i=0;i<n;i++)
         {
             start=max(start,arr[i]);
             end+=arr[i];
         }
        return findPagesUtil(arr,start,end,m,n); 
    }