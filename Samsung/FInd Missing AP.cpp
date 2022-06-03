// O(LogN)
// Binary Search
int findMissing(int arr[], int n) {
        // code here
        int d=(arr[n-1]-arr[0])/n;
        int low=0,high=n-1;
        int best=0;
        while(low<=high)
        {
            int mid=(low+high)/2;
            int actualVal=arr[0]+(mid*d);
            if(arr[mid]>actualVal)
             {
                high=mid-1;
                best=mid;
             }
            else
             {
                 low=mid+1;
             }
        }
        return arr[0]+(best*d);
    }