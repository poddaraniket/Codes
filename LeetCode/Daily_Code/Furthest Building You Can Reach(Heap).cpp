class Solution {
public:
    
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> pq;
        int i;
        for(i=1;i<heights.size();i++){
            int gap=heights[i]-heights[i-1];
            if(gap<=0)
                continue;
            bricks-=gap;
            pq.push(gap);
            if(bricks<0){
                bricks+=pq.top();
                pq.pop();
                ladders--;
            }
           if(ladders<0){
               break;
           } 
        }
        return i-1;
    }
};