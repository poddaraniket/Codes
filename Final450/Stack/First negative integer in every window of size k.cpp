vector<long long> printFirstNegativeInteger(long long int A[],long long int N, long long int K){
 vector<long long> v;
 deque<int> dq;
 long long int i=0;
 for(i=0;i<K;i++)
 {
     if(A[i]<0)
      dq.push_back(i);
 }
 for(;i<N;i++)
 {
    if(dq.empty())
     v.push_back(0);
    else 
     v.push_back(A[dq.front()]);
    while(!dq.empty() && dq.front()<=i-K)
     {
         dq.pop_front();
     }
    if(A[i]<0)
     dq.push_back(i);
 }
  if(dq.empty())
     v.push_back(0);
  else 
     v.push_back(A[dq.front()]);
 return v;
}