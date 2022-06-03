//O(nlogn+n)       -->Time 
//O(n)             -->Space

vector<vector<int>> merge(vector<vector<int>>& intervals) {
       vector<vector<int>>v;
       vector<pair<int,bool>> check;
       sort(intervals.begin(),intervals.end(),cmp);
       vector<int> temp;
       temp.push_back(intervals[0][0]);
       temp.push_back(intervals[0][1]);
       for(int i=1;i<intervals.size();i++){
          // cout<<temp.back()<<endl;
           if(temp.back()>=intervals[i][0]){   
               if(temp.back()<=intervals[i][1]){
                   temp.pop_back();
                   temp.push_back(intervals[i][1]);
               }
           }else{
               if(!temp.empty()){
                   v.push_back(temp);
                   temp.clear();
                   temp.push_back(intervals[i][0]);
                   temp.push_back(intervals[i][1]);
               }
           }
       }
       if(!temp.empty()){
          v.push_back(temp);
          temp.clear();
       }  
      return v; 
    }