int carpetBox(int A, int B, int C, int D){
        //code here
        int cnt=0,cnt1=0;
        int A1=A,B1=B;
        // A=min(A,B);
        // B=max(A,B);
        while(B>D || A>C)
        {
            if(B>D){ 
              B/=2;
              cnt++;
            }
            else if(A>C)
             {
               A/=2;
               cnt++; 
             }
            else
             break;
        }
       // cout<<cnt<<endl;
        while(A1>D || B1>C)
        {
            if(B1>C){ 
              B1/=2;
              cnt1++;
            }
            else if(A1>D)
             {
               A1/=2;
               cnt1++; 
             }
            else
             break;
        }
        //cout<<cnt1<<endl;
        return min(cnt1,cnt);
    }