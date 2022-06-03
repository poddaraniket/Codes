void threeWayPartition(vector<int>& array,int a, int b)
    {
        // code here 
        int start=0,end=array.size()-1;
        for(int i=0;i<=end;)
        {
            if(array[i]<a)
                swap(array[i++],array[start++]);
            else if(array[i]>b)
                swap(array[i],array[end--]);
            else
             i++;
        }   
    }