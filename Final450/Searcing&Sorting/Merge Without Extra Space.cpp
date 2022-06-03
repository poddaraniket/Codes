void merge(int arr1[], int arr2[], int n, int m) {
	   int gap=ceil((double)(n+m)/2);
	   // makes sure when gap is 1 the check is done only once due to ceil 
	   // the gap at the end always remains 1 so when once gap=1 id done drop bcoms 0
	   // loop exits
	   int drop=2;
	   while(drop){
	       for(int i=0;i<(m+n-gap);i++){
	           if(i<n){
	               if(i+gap<n)
	                {
	                    if(arr1[i]>arr1[i+gap])
	                       swap(arr1[i],arr1[i+gap]);
	                }
	               else 
	                 {
	                     if(arr1[i]>arr2[i+gap-n])
	                       swap(arr1[i],arr2[i+gap-n]);
	                 }
	           }
	           else{
	               int temp=i-n;
	               if(temp+gap<m && arr2[temp]>arr2[temp+gap])
	                {
	                    swap(arr2[temp],arr2[temp+gap]);
	                }
	           }
	       }
	      gap=ceil((double)gap/2);
	      if(gap==1)
	       drop--;
	   }
	}