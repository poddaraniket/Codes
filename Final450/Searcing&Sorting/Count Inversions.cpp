long long merge(long long arr[],int low,int mid,int high){
    long long count=0;
    int n1=mid-low+1;
    int n2=high-mid;
    long long L[n1];
    long long R[n2];
    for(int i=0;i<n1;i++){
        L[i]=arr[low+i];
    }
    for(int j=0;j<n2;j++){
        R[j]=arr[mid+1+j];
    }
    int i=0,j=0,k=low;
    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            arr[k]=L[i];
            i++;
            
        }else{
            arr[k]=R[j];
            j++;
           // cout<<L[i]<<" "<<R[j]<<endl;
            count+=(n1-i);
        }
        k++;
    }
    while(i<n1){
        arr[k]=L[i];
        k++;
        i++;
    }

    while(j<n2){
        arr[k]=R[j];
        k++;
        j++;
    }
    return count;
}

long long mergeSort(long long arr[],int low,int high){
    long long count=0;
    if(low<high)
    {
    int mid=(low+high)/2;
    count+=mergeSort(arr,low,mid);
    count+=mergeSort(arr,mid+1,high);
    count+=merge(arr,low,mid,high);
    }
    return count;
}

// arr[]: Input Array
// N : Size of the Array arr[]
// Function to count inversions in the array.
long long inversionCount(long long arr[], long long N)
{
    // Your Code Here
    return mergeSort(arr,0,N-1);
    // for(int i=0;i<N;i++){
    //     cout<<arr[i]<<endl;
    // }
    //return count;
}
