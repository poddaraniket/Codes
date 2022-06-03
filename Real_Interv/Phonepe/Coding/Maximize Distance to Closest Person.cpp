 int maxDistToClosest(vector<int>& seats) {
       int maxGap=0;
       int currentGap=0;
       bool one=false; 
       for(int i=0;i<seats.size();i++)
        {
           if(seats[i]==1)
            {
              if(!one) 
                maxGap=max(maxGap,currentGap);
              else
                maxGap=max(maxGap,currentGap/2);
              one=true; 
              currentGap=1;
            }
           else
            {
               currentGap++;
            }
        }
        
       maxGap=max(currentGap-1,maxGap);
       return maxGap; 
    }