string reorganizeString(string s) {
        int arr[26]={0};
        //stored character count
        for(int i=0;i<s.length();i++)
        {
            arr[s[i]-'a']++;
        }
        //Stored pair in queue and also checked if any character occurs mre than half the length
        priority_queue<pair<int,char>> pq;
        for(int i=0;i<26;i++){
            if(arr[i]!=0){
                pq.push({arr[i],(char)(i+'a')});
                if(arr[i]>(s.length()+1)/2)
                    return ""; 
            }
        }
        
        pair<int,char> prev;
        prev.first=0;
        prev.second='$';
        string str="";
        while(!pq.empty()){
            pair<int,char> temp=pq.top();
            pq.pop();
            str+=temp.second;
            temp.first--;
            if(prev.first!=0)
             {
                pq.push(prev);
             }
            prev.first=temp.first;
            prev.second=temp.second;
        }
        return str;
    }