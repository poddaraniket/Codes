
//Expected Time Compelxity: O(N^2 * M)
//Expected Auxiliary Space: O(N * M) where N = length of card and M = |cardi|

int wordLadderLength(string startCard, string endCard, vector<string>& card) {
        // Code here
        int locStart=-1,locEnd=-1;
        for(int i=0;i<card.size();i++)
         {
            if(startCard==card[i])
             locStart=i; 
            if(endCard==card[i])
             locEnd=i;
         }
        //cout<<locStart<<" "<<locEnd<<endl; 
        if(locEnd==-1)
         return 0;
        if(locStart!=-1)
         card.erase(card.begin()+locStart);
        queue<string> q; 
        q.push(startCard);
        //card.erase(card.begin()+locStart+1);
        int depth=0;
        //cout<<"*"<<endl;
        while(!q.empty()) //O(W)
         {
             depth+=1;
             int lsize=q.size();
             while(lsize--) 
             {
                string curr=q.front();
                q.pop();
                if(curr.length()!=endCard.length())
                    continue;
                for(int i=0;i<curr.length();i++)  // O(N)
                 {
                     string temp=curr;
                     for(char c='a';c<='z';c++)  //O(26)
                      {
                        temp[i]=c;
                        if(temp==curr)
                         continue;
                        if(temp==endCard)
                          return depth+1;
                        for(int j=0;j<card.size();j++) //O(N)
                         {
                            if(temp==card[j])
                             {
                                 q.push(temp);
                                 card.erase(card.begin()+j);
                                 //cout<<temp<<" "<<card.size()<<endl;
                             }
                         }
                      }
                 }
             }
         }
        return 0; 
    }