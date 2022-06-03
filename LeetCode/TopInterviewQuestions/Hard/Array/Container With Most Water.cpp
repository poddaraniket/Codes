class Solution {
public:
    int maxArea(vector<int>& height) {
        int area=0;
        int l=0,r=height.size()-1;
        while(l<r){
            area=max(area,min(height[r],height[l])*(r-l));
            if(height[r]<height[l])
               r--;
            else
                l++;
        }
        return area;
    }
};