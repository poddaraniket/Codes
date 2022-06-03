//O(NlogN)

int minSpeedOnTime(vector<int>& dist, double hour) {
     long long int totalDist=0;
     int n=dist.size();
     for(int i=0;i<n;i++)
      {
         totalDist+=dist[i];
      }
     int l=floor((double)totalDist/hour);
     int h=10000000;
     int best=-1;
     while(l<=h)
     {
         int m=l+(h-l)/2;
         double s=0;
         int i=0;
         for(i=0;i<n-1;i++)
          {
             s+=ceil((double)dist[i]/(double)m);
          }
         s+=(double)dist[i]/(double)m;
         if(s<=hour)
          {
             h=m-1;
             best=m;
          }
         else
         {
             l=m+1;
         }
     }
     return best;
 }