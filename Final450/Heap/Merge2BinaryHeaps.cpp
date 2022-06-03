void MaxHeapify(vector<int> &merged,int parent,int size){
        int left=2*parent+1; 
        int right=2*parent+2;
        int largest=parent;
        if(left<size && merged[left]>merged[largest])
          largest=left;
        if(right<size && merged[right]>merged[largest])
          largest=right;
        if(largest!=parent)
         {
             //cout<<merged[largest]<<" "<<merged[parent]<<endl;
             swap(merged[largest],merged[parent]);
             //cout<<merged[largest]<<" "<<merged[parent]<<endl;
             MaxHeapify(merged,largest,size);
         }
    }
    
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        vector<int> merged(n+m);
        for(int i=0;i<n;i++)
         merged[i]=a[i];
        for(int i=0;i<m;i++)
         merged[n+i]=b[i]; 
        // for(int i=0;i<(n+m);i++)
        //  cout<<merged[i]<<endl;
        for(int i=(n+m)/2-1;i>=0;i--)
         {
             MaxHeapify(merged,i,n+m);
         }
        return merged; 
   