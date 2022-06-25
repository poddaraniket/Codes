/*
It may first seem that it can be done by dynamic programming. In this approach we can create all possible subsequences of the courses and return the maximum length of the courses. But in this case we will not consider the order of the courses which is very important to maximise the courses done. So this approach will not work. So we have to take other approach.
*/

//O(NlogN)

class Solution {
public:
    
    static bool cmp(vector<int> &a, vector<int> &b){
        return a[1] < b[1];
    }
    
    int scheduleCourse(vector<vector<int>>& courses) {
        priority_queue<int> pq;
        int time=0;
        sort(courses.begin(),courses.end(),cmp);
        for(vector<int> course : courses){
            if(time+course[0]<=course[1]){
                time+=course[0];
                pq.push(course[0]);
            }else if(!pq.empty() && pq.top()>course[0]){
                time=time-pq.top()+course[0];
                pq.pop();
                pq.push(course[0]);
            }
        }
        return pq.size();
    }
};