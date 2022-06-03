int getPosition(int arr1[],int arr2[],int n,int m,int k)
    {
        // (k-m) bcoz if second array has elements lesser than k u can't pick up 0 from first
        int low=max(0,k-m);
        int high=min(n,k);
        while(low<=high)
        {
            int partitionX=(low+high)/2;
            int partitionY=k-partitionX;
            //cout<<partitionX<<" "<<partitionY<<endl;
            int maxLeftX=(partitionX==0)?INT_MIN:arr1[partitionX-1];
            int minRightX=(partitionX==n)?INT_MAX:arr1[partitionX];
            int maxLeftY=(partitionY==0)?INT_MIN:arr2[partitionY-1];
            int minRightY=(partitionY==m)?INT_MAX:arr2[partitionY];
            if(maxLeftX<=minRightY && maxLeftY<=minRightX)
             {
                return max(maxLeftX,maxLeftY); 
             }
            else if(maxLeftX>minRightY) 
             high=partitionX-1;
            else
             low=partitionX+1;
        }
        return 1;
    }
    
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
       if(n<m)
        return getPosition(arr1,arr2,n,m,k);
       else
        return getPosition(arr2,arr1,m,n,k);
    }