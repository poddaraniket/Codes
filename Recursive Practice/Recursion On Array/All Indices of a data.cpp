/*
vector<int> allIndex(vector<int>& arr, int idx, int data, int count)
{
    // when we reach the end create a list of size same as count
    if(idx==arr.size()){
        vector<int> v(count);
        return v;
    }
    
    // while going in recursion we keep the count of indices that match with data
    if(arr[idx]==data)
      count++;
    vector<int> v=allIndex(arr, idx+1, data, count);
    
    // while coming out from recursion we insert the indices in the list as per count 
    if(arr[idx]==data){
        v[count-1]=idx;
    }
    return v;
}
*/



/*
vector<int> allIndex(vector<int>& arr, int idx, int data, int count)
{
    if(idx==arr.size()){
        vector<int> v(count);
        return v;
    }
    
    
    if(arr[idx]==data){
        // while going in recursion we increase the count of indices that match with data
        vector<int> v=allIndex(arr, idx+1, data, count+1);
        // while coming out from recursion we insert the indices
        // bcoz wen it will come out from here index do have the data present
        v[count-1]=idx;
        return v;
    }else{
        // while going in recursion we do not increase the count of indices if do not match with data
        vector<int> v=allIndex(arr, idx+1, data, count+);
        // while coming out from recursion we do not insert the index
        // bcoz wen it will come out from here index don't have the data present
        return v;
    }
    
     
    if(arr[idx]==data){
       
    }
    return v;
}


*/
int main() {
  int n ;
  cin >> n;
  vector<int> arr;
  for (int i = 0; i < n; i++) {
    int d;
    cin >> d;
    arr.push_back(d);
  }
  int data;
  cin >> data;
  vector<int> ans = allIndex(arr, 0, data, 0);
  if (ans.size() == 0) {
    cout << endl;
    return 0;
  }
  for (int ele : ans) cout << ele << endl;

  return 0;
}