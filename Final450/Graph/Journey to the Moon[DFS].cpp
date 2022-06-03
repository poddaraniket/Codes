#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'journeyToMoon' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY astronaut
 */

void dfs(vector<int> adj[],int src,vector<bool> &vis,long long int &count)
{
    cout<<src<<endl;
    vis[src]=true;
    count++;
    for(int i=0;i<adj[src].size();i++)
     {
         if(!vis[adj[src][i]])
          dfs(adj,adj[src][i],vis,count);
     }
}

long long int journeyToMoon(int n, vector<vector<int>> astronaut) {
    vector<long long int> element;
    vector<bool> vis(n,false);
    vector <int> adj[n];
    for(int i=0;i<astronaut.size();i++)
     {
         adj[astronaut[i][0]].push_back(astronaut[i][1]);
         adj[astronaut[i][1]].push_back(astronaut[i][0]);
     }
    for(int i=0;i<n;i++)
     {
         if(!vis[i])
          {
             long long int count=0;
             dfs(adj,i,vis,count);
             element.push_back(count);  
          }
     }
    long long int size=element.size();
    vector<long long int> total(size);
    total[size-1]=element[size-1]; 
    for(int i=element.size()-2;i>=0;i--)
     {
         total[i]=total[i+1]+element[i];
     }
    long long int sum=0; 
    for(int i=1;i<element.size();i++)
     sum+=(element[i-1]*total[i]);  
    return sum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int p = stoi(first_multiple_input[1]);

    vector<vector<int>> astronaut(p);

    for (int i = 0; i < p; i++) {
        astronaut[i].resize(2);

        string astronaut_row_temp_temp;
        getline(cin, astronaut_row_temp_temp);

        vector<string> astronaut_row_temp = split(rtrim(astronaut_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int astronaut_row_item = stoi(astronaut_row_temp[j]);

            astronaut[i][j] = astronaut_row_item;
        }
    }

    long long int result = journeyToMoon(n, astronaut);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
