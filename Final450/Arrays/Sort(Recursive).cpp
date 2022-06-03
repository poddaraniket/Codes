void insert(vector<int> &arr,int temp){
    if(arr.size()==0 || arr[arr.size()-1]<=temp)
     {
         arr.push_back(temp);
         return;
     }
    int x=arr[arr.size()-1];
    arr.pop_back();
    insert(arr,temp);
    //inseting rest of the eelments after inserting temp
    arr.push_back(x);
    return;
}


// Remove Last element an sort the rest 
void sort(vector<int> &arr){
    if(arr.size()==1)
     return;
    // store the last element
    int temp=arr[arr.size()-1];
    arr.pop_back();
    sort(arr);
    
    // Add the last element to proper location in the sotred array 
    insert(arr,temp);
}




class Solution{
    public:
    vector<int> sortArr(vector<int>arr, int n){
    //complete the function here
    sort(arr);
    return arr;
    }