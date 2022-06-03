//O(N+M)

void lps(string pat,int lp[],int N)
{
	 lp[0]=0;
	 int i=1,j=0;
	 while(i<N)
	  {
	      if(pat[i]==pat[j])
	       {
	           j++;
	           lp[i]=j;
	           i++;
	       }
	      else
	       {
	           if(j!=0)
	            {
	               j=lp[j-1];  // i remain same 
	            }
	           else
	            {
	                lp[i]=0;
	                i++;
	            }
	       }
	  }
}
    
vector <int> search(string pat, string txt)
{
    //code hee.
    int N=pat.length();
    int M=txt.length();
    int lp[N];
    lps(pat,lp,N);
    vector<int> v;
    int i=0,j=0;
    while(j<M)
     {
         if(pat[i]==txt[j])
          {
              i++;
              j++;
          }
         if(i==N)
          {
              v.push_back(j-N+1);
              i=lp[i-1];
          }
         else if(j<M && pat[i]!=txt[j])
          {
              if(i!=0)
               {
                   i=lp[i-1];
               }
              else
               {
                   // i is O so it will start from 0 automatically 
                   // since i is 0 we know no char will match before i
                   // therefore increase j by 1
                   j++;
               }
          }
     }
    return v; 
}