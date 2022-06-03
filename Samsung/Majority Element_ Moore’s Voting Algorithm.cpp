//O(N) O(1)  Moore’s Voting Algorithm

int findCandidate(int arr[],int n)
    {
        int maxIndex=0,count=1;
        for(int i=1;i<n;i++)
        {
            if(arr[maxIndex]==arr[i])
             {
                count++;
             }
            else
             count--;
            if(count==0)
            {
                maxIndex=i;
                count=1;
            }
        }
        return maxIndex;
    }

    int majorityElement(int arr[], int size)
    {
        if(size==1)
         return arr[0];
        // your code here
        int index=findCandidate(arr,size);
        int val=arr[index];
        int count=0;
        for(int i=0;i<size;i++){
            if(arr[i]==val)
             count++;
        }
        return (count>(size/2)) ? val : -1;
    }