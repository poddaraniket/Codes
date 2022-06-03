//O(N^2)

int maxWait=0;
class Solution 
{
    
    public:
    //Function to find the maximum profit and the number of jobs done.
    
    static bool cmp(Job a1,Job a2)
    {
        maxWait=max(maxWait,max(a1.profit,a2.profit));
        return a1.profit>a2.profit;
    }
    
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr,arr+n,cmp);
        int timing[maxWait]={0},prof=0,count=0;
        for(int i=0;i<n;i++){
            int start=arr[i].dead; 
            //Binary Search for logN compplexity over here
            while(start--)
             {
                if(timing[start]==0)
                 {
                     timing[start]=1;
                     prof+=arr[i].profit;
                     count++;
                     break;
                 }
             }
        }
        vector<int> v;
        v.push_back(count);
        v.push_back(prof);
        return v;
    } 
};