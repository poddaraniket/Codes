#include <bits/stdc++.h>
using namespace std;
 
const int MAX = 100;
 
int countPositional(int a[][MAX], int m, int n)
{
    // rwomax[i] is going to store maximum of
    // i-th row and other arrays have similar
    // meaning
    int rowmax[m], rowmin[m];
    int colmax[n], colmin[n];
 
    // Find rminn and rmaxx for every row
    for (int i = 0; i < m; i++) {
        int rminn = INT_MAX;
        int rmaxx = INT_MIN;
        for (int j = 0; j < n; j++) {
            if(a[i][j]==rmaxx || a[i][j]==rminn) 
              return -1;
            if (a[i][j] > rmaxx)
                rmaxx = a[i][j];
            if (a[i][j] < rminn)
                rminn = a[i][j];
        }
        rowmax[i] = rmaxx;
        rowmin[i] = rminn;
    }
 
    // Find cminn and cmaxx for every column
    for (int j = 0; j < n; j++) {
        int cminn = INT_MAX;
        int cmaxx = INT_MIN;
        for (int i = 0; i < m; i++) {
            if(a[i][j]==cmaxx || a[i][j]==cminn) 
              return -1;
            if (a[i][j] > cmaxx)
                cmaxx = a[i][j];
            if (a[i][j] < cminn)
                cminn = a[i][j];
        }
 
        colmax[j] = cmaxx;
        colmin[j] = cminn;
    }
 
    // Check for optimal element
    int count = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if ((a[i][j] == rowmax[i])
                || (a[i][j] == rowmin[i])
                || (a[i][j] == colmax[j])
                || (a[i][j] == colmin[j])) {
                count++;
            }
        }
    }
 
    return count;
}
 
// Driver code
int main()
{
    int a[][MAX] = { { 1, 3, 4 },
                     { 5, 2, 9 },
                     { 8, 7, 6 } };
    int m = 3, n = 3;
    cout << countPositional(a, m, n);
    return 0;
}