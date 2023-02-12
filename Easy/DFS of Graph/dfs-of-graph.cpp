//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(int n,vector<int> &ds,vector<int> adj[],int vis[]){
        ds.push_back(n);
        vis[n]=1;
        for(auto it:adj[n]){
            if(!vis[it]){
                dfs(it,ds,adj,vis);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
       vector<int> ds;
       int vis[V+1]={0};
       vis[0]=1;
       dfs(0,ds,adj,vis);
       return ds;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends