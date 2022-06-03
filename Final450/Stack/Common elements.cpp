vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            //code here.
            //int n=min(min(n1,n2),n3);
            vector<int> v;
            int i=0,j=0,k=0;
            while(1){
                //cout<<i<<" "<<j<<" "<<k<<endl;
                if(i>=n1 || j>=n2 || k>=n3)
                 break;
                if(A[i]==B[j] && B[j]==C[k])
                 {
                     if(v.size()==0)
                       v.push_back(A[i]);
                     else
                        {
                            if(v.back()!=A[i])
                              v.push_back(A[i]);
                        }
                       
                     i++;
                     j++;
                     k++;
                 }
                else{
                    int m=max(max(A[i],B[j]),C[k]);
                   // cout<<m<<endl;
                    if(A[i]!=m)
                     i++;
                    if(B[j]!=m)
                     j++;
                    if(C[k]!=m)
                     k++;
                } 
            }
            return v;
        }