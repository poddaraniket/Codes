bool check(int num,int n){
            int f=5,count=0;
            while(f<=num)
             {
                 count+=(num/f);  // [x/5]+[x/25]+[x/125]..........
                 f*=5;
             }
            return (count>=n); 
        }
    
        int findNum(int n)
        {
        //complete the function here
          if(n==1)
           return 5;
          int low=0;
          int high=5*n;
          while(low<high)
          {
              int mid=(low+high)/2;
              if(check(mid,n))  // checks if the given number(mid) is the factorial we want
               high=mid;
              else
               low=mid+1;
          }
          return low;
        }