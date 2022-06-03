int maxLength(vector<int> arr,int n){
           //code here
          int pos=0,neg=0,res=0;
          for(int i=0;i<n;i++){
              if(arr[i]==0)
               {
                   pos=0;
                   neg=0;
               }
              else if(arr[i]>0)
               {
                   pos++;
                   if(neg!=0)
                    neg++;
                   cout<<pos<<" "<<neg<<endl;    
                   res=max(res,pos);    
               }
              else
               {
                   swap(pos,neg);
                   neg++;
                   if(pos!=0)
                    pos++;
                   cout<<pos<<" "<<neg<<endl;    
                   res=max(res,pos);    
               }
          } 
        return res;  
    }