void sort012(int a[], int n)
    {
        // coode here
        int l=0,m=0,r=n-1;
        while(m<=r)
         {
             if(a[m]==0)
              {
                  swap(a[l++],a[m++]);
              }
             else if(a[m]==1)
              m++;
             else
              swap(a[r--],a[m]);
         }
    }