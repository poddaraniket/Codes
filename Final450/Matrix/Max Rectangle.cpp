int maxAreaTillRow(vector<int>& heights) {
    
    // When calculating the largets area one bar is always entirely included    
        
    int size=heights.size();   
    // 1.Find the largest area including one particular bar at a time
        
       // 1.1 Find the left most limit for the current bar [nearest leftmost bar with height < current bar]
         int left[size];
         stack<int> leftStack;
         for(int i=0;i<size;i++){                            //O(N)
            while(!leftStack.empty()){
                int top=leftStack.top();
                //cout<<top<<" "<<i<<endl;
                if(heights[top]>=heights[i]){
                   // cout<<i<<endl;
                    leftStack.pop();
                }else{
                    break;
                }
            }
            if(leftStack.empty()){
               // cout<<i<<endl;
                left[i]=0;
            }else{
                left[i]=leftStack.top()+1;
            } 
            leftStack.push(i); 
         }
        
      // 1.2 Find the right most limit for the current bar [nearest righmost bar with height < current bar] 
         int right[size];
         stack<int> rightStack;
         for(int i=size-1;i>=0;i--){
            while(!rightStack.empty()){
                int top=rightStack.top();
                if(heights[top]>=heights[i]){
                    rightStack.pop();
                }else{
                    break;
                }
            }
            if(rightStack.empty()){
                right[i]=size-1;
            }else{
                right[i]=rightStack.top()-1;
            } 
            rightStack.push(i); 
         }
         
      // 1.3 calculate the area inculding that the bar [ht of the bar * (right[bar]-left[bar]+1)
          int area[size];
          for(int i=0;i<size;i++){
              area[i]=heights[i] * (right[i]-left[i]+1);
          }
        
    // 2.Find the largest among all the areas
        int maxArea=-1;
        for(int i=0;i<size;i++){
            //cout<<i<<"->"<<left[i]<<" "<<right[i]<<" "<<area[i]<<endl;
            maxArea=max(maxArea,area[i]);
        }
        
        return maxArea;
    }
/*You are required to complete this method*/
class Solution{
  public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        /*
        Take Each row as a sum of previous row and itself and 
        solve that row like finding largest Rectangular histogram
        */
        vector<int> v(m,0);
        int maxArea=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               if(M[i][j]==0)
                 v[j]=0;
               else
                 v[j]+=M[i][j];
            }
            maxArea=max(maxAreaTillRow(v),maxArea);
        }
        return maxArea;
    }
};