//Time Complexity: O(n*logn) n-> for creation of heap and logn for insertion

int kthSmallest(int arr[], int l, int r, int k) {
        //code here
       int n=r-l+1;
       priority_queue<int> pq;
       for(int i=0;i<n;i++){
           if(i<=k-1){
               pq.push(arr[i]);
           }
           else{
               if(arr[i]<pq.top()){
                   pq.pop();
                   pq.push(arr[i]);
               }
           }
       }
      return pq.top(); 
    }