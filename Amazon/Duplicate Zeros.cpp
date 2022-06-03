class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int count=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==0){
                count++;
            }
        }
        
        int l=arr.size()-1,r=l+count;
        while(l<r){
            cout<<l<<" "<<r<<endl;
            if(arr[l]==0){
                if(r<arr.size()){
                    arr[r]=0;
                }
                r--;
            }
            if(r<arr.size())
              arr[r]=arr[l];
            l--;
            r--;
        }
    }
};