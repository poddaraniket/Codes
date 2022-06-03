int getPairsCount(int arr[], int n, int k) {
        // code here
        int count[1000001]={0};
        for(int i=0;i<n;i++){
            count[arr[i]]++;
        }
        int sum=0;
        for(int i=0;i<n;i++){
            int val=arr[i];
            count[arr[i]]--;
            if(k-arr[i]>0 && k-arr[i]<=1000000)
              sum+=count[k-arr[i]];
            //cout<<sum<<endl;
        }
        return sum;
    }