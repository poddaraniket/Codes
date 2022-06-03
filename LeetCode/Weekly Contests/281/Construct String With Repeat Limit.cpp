//O(NlogN)

class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        string newS="";
        priority_queue<pair<char,int>> pq;
        int freq[30]={0};
        for(int i=0;i<s.length();i++){
            freq[s[i]-'a']++;
        }
        for(int i=0;i<30;i++){
            if(freq[i]!=0){
                pq.push({(char)(i+97),freq[i]});
            }
        }
        while(!pq.empty()){
            pair<char,int> highest=pq.top();
            pq.pop();
            int count=highest.second;
            char c=highest.first;
            for(int i=0;i<repeatLimit && count>0;i++){
                    newS+=c;
                    count--;
            }
            if(count >0 && pq.size()>0){
                pair<char,int> secondHighest=pq.top();
                pq.pop();
                newS+=secondHighest.first;
                secondHighest.second--;
                if(secondHighest.second>0){
                    pq.push(secondHighest);
                }
                pq.push({c,count});
            }
        }
        return newS;
    }
};