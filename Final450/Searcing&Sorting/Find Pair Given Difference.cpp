bool findPair(int arr[], int size, int n){
    //code
    sort(arr,arr+size);
    /* Can't do this bcoz wen u do s++ u increase value in arr[s] 
        and thus dec the diff and if u do e-- u dec value in arr[e] 
        and still dec the diff so u can't decide
        u have to do soemthing where in one way u inc diff and other u dec
    */
    // int s=0,e=size-1;
    // while(s<e){
    //     int diff=arr[e]-arr[s];
    //     if(diff>n)
    //      e--;
    //     else if(diff<n)
    //      s++;
    //     else
    //      return true;
    // }
    // return false;
    
    // Here by inc j u inc diff and by inc i u dec diff
    int i=0,j=1;
    while(j<size){
        if(arr[j]-arr[i]==n)
         return true;
        else if(arr[j]-arr[i]<n)
         j++;
        else
         i++;
    }
    return false;
}