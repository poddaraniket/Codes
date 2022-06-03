//O(NlogN)

void quickSort(int arr[], int low, int high)
    {
        // code here
        if(low<high)
        {
            int pi=partition(arr,low,high);
            quickSort(arr,low,pi-1);
            quickSort(arr,pi+1,high);
        }
    }
        
    int partition (int arr[], int low, int high)
    {
       // Your code here
       int i=(low-1);
       int pivot=arr[high];
       for(int j=low;j<=high-1;j++)
        {
            if(arr[j]<pivot)
            {
                i++;
                // placing all values less than pivot to the start
                swap(arr[i],arr[j]);
            }
        }
        //placing the pivot in its correct position such that values to left are smaller
        // values to right ar elarger then pivot
        swap(arr[i+1],arr[high]);
        return i+1;
    }