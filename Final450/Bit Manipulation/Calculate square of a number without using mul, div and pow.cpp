//O(logn)
#include <bits/stdc++.h>
using namespace std;

// n -> even (n=2*x) => n^2=(2*x)^2
// n -> odd  (n=2*x+1) => n^2=(2*x+1)^char32_t


int square(int n)
{
    if(n==0)
     return 0;
    if(n<0)
     n=-n;
    
    if(n%2==0)
     return 4*square(n/2);
    else
     return 4*square(n/2)+4*(n/2)+1;
}

int main()
{
    // Function calls
    for (int n = 1; n <= 5; n++)
        cout << "n = " << n << ", n^2 = " << square(n)
             << endl;
    return 0;
}