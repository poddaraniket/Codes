//O((n+m)log(n+m)) -> Times
	void merge(int arr1[], int arr2[], int n, int m) {
	   int gap=ceil((double)(n+m)/2); 
	   int drop=2;
	   while(drop){
	       for(int i=0;i<(m+n-gap);i++){
	           if(i<n){
	               if(i+gap<n){
	                   if(arr1[i]>arr1[i+gap])
	                       swap(arr1[i],arr1[i+gap]);
	                   }
	               }else{
	                    if(arr1[i]>arr2[i+gap-(n-1)-1]){
	                       swap(arr1[i],arr2[i+gap-(n-1)-1]);
	                   }  
	               }
	           }else{
	               int temp=i-(n-1)-1;
	               if(arr2[temp]>arr2[temp+gap]){
	                   swap(arr2[temp],arr2[temp+gap]);
	               }
	           }
	       }
	       gap=ceil((double)gap/2);
	       if(gap==1)
	        drop--;
	       
	   }