void rotate(int arr[], int n)
{
    for(int i=n-2;i>=0;i--){
        arr[i]^=arr[i+1];
        arr[i+1]^=arr[i];
        arr[i]^=arr[i+1];
        //swap(arr[i],arr[i+1]);
    }
}