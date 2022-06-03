int equalStacks(vector<int> h1, vector<int> h2, vector<int> h3) {
        int sum1=0,sum2=0,sum3=0;
        for(int i=0;i<h1.size();i++)
         {
             sum1+=h1[i];
         }
        for(int i=0;i<h2.size();i++)
         {
             sum2+=h2[i];
         }
        for(int i=0;i<h3.size();i++)
         {
             sum3+=h3[i];
         }
        int top1=0,top2=0,top3=0; 
        while(1){
            if(top1==h1.size() || top2==h2.size() || top3==h3.size())
              return 0;
            if(sum1==sum2 && sum2==sum3)
             return sum2;
            if(sum1>=sum2 && sum1>=sum3)
             sum1-=h1[top1++];
            else if(sum2>=sum1 && sum2>=sum3)
             sum2-=h2[top2++]; 
            else if(sum3>=sum1 && sum3>=sum2)
             sum3-=h3[top3++];    
        }  
}