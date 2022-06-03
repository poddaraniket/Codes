 string chooseandswap(string a){
        // Code Here
        set<char> s;
        int n=a.length();
        int i;
        for(i=0;i<n;i++) //O(26) = O(1) [Sapce]
         {
             s.insert(a[i]);
         }
        for(i=0;i<n;i++)   // O(N) [Time]
         {
             if(s.empty())
              break;
             if(a[i]>*s.begin())
              {
                break;  
              }
             else if(a[i]==*s.begin())
              {
                  s.erase(s.begin());
              }
         }
        if(s.empty())
         return a;
        char toReplace=a[i];
        char byReplace=*s.begin();
        for(i=0;i<n;i++)
         {
             if(a[i]==toReplace)
              a[i]=byReplace;
             else if(a[i]==byReplace)
              a[i]=toReplace;
         }
        return a; 
    }
    