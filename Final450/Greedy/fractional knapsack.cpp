static bool cmp(Item a1,Item a2)
    {
        return ((double)a1.value/(double)a1.weight)>((double)a2.value/(double)a2.weight);
    }
    
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        sort(arr,arr+n,cmp);
        double profit=0;
        for(int i=0;i<n;i++)
         {
             if(arr[i].weight<=W){
                 profit+=arr[i].value;
                 W-=arr[i].weight;
             }
            else
             {
                 profit+=((double)(arr[i].value*W)/(double)arr[i].weight);
                 break;
             }
         }
        return profit; 
    }