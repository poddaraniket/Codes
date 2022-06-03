using namespace std;

/*
* Returns < 0 if 'b' is closer to 'a' compared to 'c', == 0 if 'b' and 'c' are same distance from 'a'
* or > 0 if 'c' is closer to 'a' compared to 'b'.
*/
int distance(pair<int,int>&a,pair<int,int>&b,pair<int,int>&c)
{
    int x1=a.first-b.first;
    int y1=a.second-b.second;
    int dist1=(y1*y1)+(x1*x1);
    int x2=a.first-c.first;
    int y2=a.second-c.second;
    int dist2=(y2*y2)+(x2*x2);
    return dist1-dist2;
}

/*
* Cross product to find where c belongs in reference to vector ab.
* If result > 0 it means 'c' is on left of ab
*    result == 0 it means 'a','b' and 'c' are collinear
*    result < 0  it means 'c' is on right of ab
*/

int crossProduct(pair<int,int>&a,pair<int,int>&b,pair<int,int>&c)
{
    int x1=a.first-b.first;
    int x2=a.first-c.first;
    int y1=a.second-b.second;
    int y2=a.second-c.second;
    return y2*x1-y1*x2;
}

set<pair<int,int>> buildconvexhull(vector<pair<int,int>> &v)
{
    set<pair<int,int>> result;
    pair<int,int> start;
    start=v[0];
    //finding leftmost point
    for(int i=0;i<v.size();i++)
     {
        if(start.first>v[i].first)
         start=v[i];
     }
    pair<int,int> curr=start;
    result.insert(start);
    //cout<<start.first<<" "<<start.second<<endl;
    while(true)
     {
        set<pair<int,int>> colinear; 
        pair<int,int> next=v[0];
        for(int i=0;i<v.size();i++)
         {
             if(v[i]==curr)
              {
               continue;
              }
             int val=crossProduct(curr,next,v[i]);
             if(val>0)
              {
                next=v[i];
                colinear.clear();
              }
             // to check for colinear points 
             else if(val==0)
              {
                int dist=distance(curr,next,v[i]);
            //if val is 0 then collinear curr, next and v[i] are collinear.
            //if its collinear point then pick the further one but add closer one to list of collinear points.
                if(dist<0)
                 {
                    colinear.insert(next);
                    next=v[i];
                 }
                else
                 {
                    colinear.insert(v[i]); 
                 }
              }
            //else if val < 0 then nothing to do since v[i] is on right side of curr -> next.  
         }
        // for(auto it=colinear.begin();it!=colinear.end();it++)
        //  {
        //      result.insert(*it);                                       // considering co-linear points also
        //      //cout<<it->first<<" "<<it->second<<endl;
        //  }
        if(next==start)
         break;
        result.insert(next);
        //cout<<next.first<<" "<<next.second<<endl;
        curr=next;
     }
    return result;
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[2*n];
	    vector<pair<int,int>> v;
	    for(int i=0;i<2*n;i++)
	     {
	        cin>>a[i];
	     }
	    for(int i=0;i<2*n;i+=2)
	     v.push_back(make_pair(a[i],a[i+1]));
	    set<pair<int,int>> ans; 
	    ans=buildconvexhull(v);
	    int size=ans.size();
	    if(size<=2)
	     cout<<"-1"<<endl;
	    else
	    {
	    for(auto it=ans.begin();it!=ans.end();it++)
	     {
	         cout<<it->first<<" "<<it->second;
	         --size;
	         if(size!=0)
	          cout<<", ";
	     }
	    cout<<endl; 
	    }
	}
	return 0;
}
