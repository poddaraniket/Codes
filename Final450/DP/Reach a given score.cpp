	long long int table[n+1],i;
	memset(table, 0, sizeof(table));
	table[0]=1;                 // If 0 sum is required number of ways is 1.
	int val[3]={3,5,10};
	for(i=0;i<3;i++)
	 {
	     for(int j=1;j<=n;j++)
	      {
	          if(j>=val[i])
	           table[j]+=table[j-val[i]];
	      }
	 }
	return table[n];