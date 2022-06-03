class Solution {
public:
    int maxTurbulenceSize(vector<int>& a) {
        if(a.size()==1)
            return 1;
        
        int n=a.size();
        int l=0,r=0,frst=0,second=0,max_length=0;
        while(l<=r)
        {
            if(r>=n-1)
               break;  
            if(r%2==0)
             {
                if(a[r]>a[r+1])
                 {
                   if(frst==1)
                    {
                       second=1;
                       frst=0;
                       max_length=max(max_length,r-l+1);
                       l=r;
                    }
                   else
                   {
                       second=1;
                   }   
                  r++;  
                 }
                else if(a[r]<a[r+1])
                 {
                    if(second==1)
                    {
                       frst=1;
                       second=0;
                       max_length=max(max_length,r-l+1);
                       l=r;
                    }
                   else
                    {
                       frst=1;
                    } 
                   r++; 
                 }
                else
                {
                    max_length=max(max_length,r-l+1);
                    l=r+1;
                    r=l;
                }  
             }
            else
            {
              if(a[r]>a[r+1])
                 {
                   if(second==1)
                    {
                       frst=1;
                       second=0;
                       max_length=max(max_length,r-l+1);
                       l=r;
                    }
                   else
                   {
                       frst=1;
                   }  
                  r++;
                 }
               else if(a[r]<a[r+1])
                {
                  if(frst==1)
                    {
                       second=1;
                       frst=0;
                       max_length=max(max_length,r-l+1);
                       l=r;
                    }
                   else
                   {
                       second=1;
                   } 
                  r++; 
                }
               else
               {
                 max_length=max(max_length,r-l+1);  
                 l=r+1;
                 r=l;  
               }
            }
        }
      return max(max_length,r-l+1);  
    }
};