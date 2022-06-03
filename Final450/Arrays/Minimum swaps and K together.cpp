int minSwap(int *arr, int n, int k) {
    // Complet the function
    int good=0,bad=0,swaps=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]<=k)
         good++;
    }
    for(int i=0;i<good;i++)
    {
        if(arr[i]>k)
         bad++;
    }
    swaps=bad;
    for(int i=good;i<n;i++)
    {
        if(arr[i-good]>k)
         bad--;
        if(arr[i]>k) 
         bad++;
        swaps=min(swaps,bad); 
    }
    return swaps;