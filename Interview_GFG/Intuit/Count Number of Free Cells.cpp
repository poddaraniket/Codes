vector<long long int> countZero(int n, int k, vector<vector<int>>& arr){
      //Code Here
      map<int,int> ROW,COL;
      for(int i=0;i<=n;i++)
        {
            ROW[i]=0;
            COL[i]=0;
        }
      long long int rowCount=n,colCount=n;
      long long int total=1LL*n*n;
      vector<long long int> v;
      for(int i=0;i<k;i++)
       {
            int r=arr[i][0];
            int c=arr[i][1];
            if(total==0)
             {
                 v.push_back(0);
                 continue;
             }
            if(ROW[r]==0 && COL[c]==0)
             {
                 total-=(colCount+rowCount-1);
                 rowCount--;
                 colCount--;
                 //ROW[r]=1;
             }
            else if(COL[c]==0)
             {
                 total-=rowCount;
                 colCount--;
                 //COL[c]=1;
             }
            else if(ROW[r]==0)
             {
                total-=colCount;
                rowCount--; 
             }
            v.push_back(total);
            ROW[r]=1;
            COL[c]=1;
       }   
      return v; 
  }