//O(m+n)

int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
	    int loc=m-1,index=-1;
	    for(int i=0;i<m;i++){
	        if(arr[0][i]==1){
	            index=i;
	            loc=i;
	            break;
	        }
	    }
	    if(index!=-1){
	        loc--;
	    }
	    for(int i=1;i<n;i++){
	        while(loc>=0 && arr[i][loc]==1){
	            index=i;
	            loc--;
	        }
	    }
	    return index;
	}