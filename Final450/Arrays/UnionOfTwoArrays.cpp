// O(mlogm + nlogn + n+m)

int doUnion(int a[], int n, int b[], int m)  {
        //code here
        vector<int> v;
        sort(a,a+n);  //O(nlogn)
        sort(b,b+m);  //O(mlogm)
        int al=0,bl=0;
        if(a[al]>b[bl]){
            v.push_back(b[bl]);
            bl++;
        }else if(a[al]<b[bl]){
            v.push_back(a[al]);
            al++;
        }else{
             v.push_back(a[al]);
             al++;
             bl++;
        }
        
        //(O(m+n))
        while(1){
          //  cout<<bl<<endl;
            if(al>=n || bl>=m)
             break;
            if(a[al]<b[bl]){
             if(a[al]!=v.back())    
               v.push_back(a[al]);
             al++;
            }
            else if(a[al]>b[bl]){
               // cout<<"*"<<a[al]<<endl;
                if(b[bl]!=v.back())
                   v.push_back(b[bl]);
                bl++;
            } 
            else{
              //  cout<<"#"<<a[al]<<endl;
                if(a[al]!=v.back())
                  v.push_back(a[al]);
                al++;
                bl++;
            }
        }
        if(al>=n){
            for(int i=bl;i<m;i++){
                if(b[i]!=v.back())
                    v.push_back(b[i]);
            }
        }
        else if(bl>=m){
            for(int i=al;i<n;i++){
                if(a[i]!=v.back())
                    v.push_back(a[i]);
            }
        }
        // for(int i=0;i<v.size();i++)
        //   cout<<v[i]<<endl;
        return v.size();
    }