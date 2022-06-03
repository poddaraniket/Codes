//O(k(log(k))) + O(k^2(log(k)))

vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //code here
        //greater<pair<int,pair<int,int>>>
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        //O(k(log(k)))
        for(int i=0;i<K;i++)
         {
          //cout<<arr[i][0]<<endl;     
          pq.push({arr[i][0],{i,0}});
         }
        vector<int> v;
        //O(k^2(log(k)))
        while(!pq.empty()){
            pair<int,pair<int,int>> p=pq.top();
            //cout<<pq.size()<<endl;
            pq.pop();
            v.push_back(p.first);
            p.second.second++;
            if(p.second.second<K)
             {
               // cout<<" "<<p.second.second<<endl; 
                p.first=arr[p.second.first][p.second.second];
                //cout<<p.first<<endl;
                pq.push(p); 
             }
        }
        return v;
    }