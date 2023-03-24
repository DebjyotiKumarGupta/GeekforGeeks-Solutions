//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
         if (source.first == destination.first &&
            source.second == destination.second)
            return 0;
        int n = grid.size(),m =grid[0].size();
        queue<pair<int, pair<int, int>>> q;
        q.push({0,{source.first,source.second}});
        vector<vector<int>> dist(n, vector<int> (m,1e9));
        // dist[source.first][source.second]=0;
        
        int delrow[4] ={ -1,0,+1,0};
        int delcol[4] ={ 0,+1,0,-1};
        
        while(!q.empty()){
            auto it = q.front();q.pop();
            int dis = it.first, row=it.second.first, col= it.second.second;
            
            // if(row==destination.first && destination.second==col){
            //     return dis;
            // }
            // cout<<dis<<" "<<row<<" "<<col<<" ";
            for(int i=0;i<4;i++){
                int r = row+delrow[i];
                int c = col+delcol[i];
                // cout<<dist[row][col]<<" "<<endl;
                if(r>=0 && c>=0 && r<n && c<m && dis+1<dist[r][c] && grid[r][c]==1){
                    if(r==destination.first && c==destination.second) return dis+1;
                    dist[r][c] = dis+1;
                    q.push({dis+1, {r,c}});
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends