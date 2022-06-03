int count(int a)
    {
        int c=0;
        while(a)
         {
             if(a%2!=0)
              c++;
             a/=2; 
         }
        return c; 
    }
    
    string Binary(int a)
     {
         string s="";
         while(a){
             if(a%2!=0)
              s+='1';
             else
              s+='0';
             a/=2; 
         }
        reverse(s.begin(),s.end()); 
        return s; 
     }
    
    int convert(string s)
     {
         int num=0,t=0;
         for(int i=s.length()-1;i>=0;i--)
          {
              if(s[i]=='1')
               num+=pow(2,t);
              t++; 
          }
         return num; 
     }
    
    int minVal(int a, int b) {
        // code here
        int aC=count(a);
        int bC=count(b);
      //  cout<<aC<<" "<<bC<<endl;
        if(aC==bC)
         return 0;
         
        string aS=Binary(a); 
       // cout<<aS<<endl; 
        //remove bC 1's from right in aC to get X  
        if(aC>bC)
         {
            int c=0; 
            for(int i=aS.length()-1;i>=0;i--)
            {
                if(c==aC-bC)
                 break;
                if(aS[i]=='1')
                 {
                     aS[i]='0';
                     c++;
                 }
            }
         }
        // // add bC-aC 1's in aC to right 
        else
         {
            int c=0;
            for(int i=aS.length();i>=0;i--)
             {
                if(c==bC-aC)
                 break;
                if(aS[i]=='0')
                 {
                     aS[i]='1';
                     c++;
                 }
             }
            while(1)
             {
                 if(c==bC-aC)
                  break;
                 aS='1'+aS; 
                 c++;
             }
         }
       // cout<<aS<<endl;
        int x=convert(aS); 
        return x^a;
    }