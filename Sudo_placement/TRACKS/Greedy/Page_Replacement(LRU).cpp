using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    unordered_map<int,int> mp;
	    int n,i,fault=0,p=0;
	    cin>>n;
	    int pages[n];
	    for(i=0;i<n;i++)
	     cin>>pages[i];
	    int capacity;
	    cin>>capacity;
	    vector<pair<int,int>> frames(capacity);
	    //cout<<"*"<<endl;
	    for(i=0;i<n;i++)
	    {
	        if(p<capacity)
	         {
	             if(mp[pages[i]]==0)
	              {
	                 fault++; 
	                 frames[p].first=i;
	                 frames[p].second=pages[i];
	                 mp[pages[i]]=1;
	                 p++;
	              }
	             else
	              {
	                  for(int k=0;k<frames.size();k++)
	                  {
	                      if(frames[k].second==pages[i])
	                       frames[k].first=i;
	                  }
	              }
	         }
	        else
	         {
	             sort(frames.begin(),frames.end());
	             if(mp[pages[i]]==0)
	              {
	                  fault++;
	                  mp[frames[0].second]=0;
	                  frames[0].first=i;
	                  frames[0].second=pages[i];
	                  mp[pages[i]]=1;
	              }
	             else
	              {
	                 for(int k=0;k<frames.size();k++)
	                  {
	                      if(frames[k].second==pages[i])
	                       frames[k].first=i;
	                  } 
	              }
	         }
	    }
	   cout<<fault<<endl; 
	}
	return 0;
}