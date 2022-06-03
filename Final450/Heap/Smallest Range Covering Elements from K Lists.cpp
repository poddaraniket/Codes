vector<int> smallestRange(vector<vector<int>>& nums) {
    vector<int> v(2);
    int range=INT_MAX;
    int low=INT_MAX;
    int high=INT_MIN;
    int k=nums.size();  priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> min_heap;
    for(int i=0;i<k;i++)
     {
         min_heap.push({nums[i][0],{i,0}});
         high=max(high,nums[i][0]);
     }
    
    while(!min_heap.empty()){
        pair<int,pair<int,int>> p=min_heap.top();
        min_heap.pop();
        low=p.first;
        if(high-low<range){
           range=high-low;
            v[0]=low;
            v[1]=high;
        }
        int listIndex=p.second.second;
        listIndex++;
        int arrayIndex=p.second.first;
        if(listIndex<nums[arrayIndex].size())
        {
            high=max(high,nums[arrayIndex][listIndex]);
            min_heap.push({nums[arrayIndex][listIndex],{arrayIndex,listIndex}});
        }
        else
        {
            break;
        }
       } 
    return v;
    }