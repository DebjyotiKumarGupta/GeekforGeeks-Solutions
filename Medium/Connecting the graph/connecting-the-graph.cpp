//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
      public:
    class DisjointSet
{
   public:
   vector<int> rank, size, parent;
    int n;
    DisjointSet(int x)
    {
        n = x;
        rank.resize(n + 1, 0);
        size.resize(n + 1);
        parent.resize(n + 1);
        for (int i = 1; i <= n; i++)
        {
            parent[i]  = i;
            size[i]=1;
        }
    }

    int finduparent(int node)
    {
        if (parent[node] == node)
            return node;
        return parent[node] = finduparent(parent[node]);
    }

    void unionbyrank(int u, int v)
    {
        int ult_u = finduparent(u);
        int ult_v = finduparent(v);

        if (ult_u == ult_v)
            return;
        if (rank[ult_v] < rank[ult_u])
        {
            parent[ult_v] = ult_u;
        }
        else if (rank[ult_u] < rank[ult_v])
        {
            parent[ult_v] = ult_u;
        }
        else
        {
            parent[ult_v] = ult_u;
            rank[ult_u]++;
        }
    }

    void unionbysize(int u, int v)
    {
        int ult_u = finduparent(u);
        int ult_v = finduparent(v);

        if (size[ult_v] < size[ult_u])
        {
            parent[ult_v] = ult_u;
            size[ult_u] += size[ult_v];
        }
        else
        {
            size[ult_u] = ult_v;
            size[ult_v] += size[ult_u];
        }
    }
};
  public:
    int Solve(int n, vector<vector<int>>& edge) {
          DisjointSet ds(n);
        int cntExtras = 0;
        for (auto it : edge) {
            int u = it[0];
            int v = it[1];
            if (ds.finduparent(u) == ds.finduparent(v)) {
                cntExtras++;
            }
            else {
                ds.unionbyrank(u, v);
            }
        }
        int cntC = 0;
        for (int i = 0; i < n; i++) {
            if (ds.parent[i] == i) cntC++;
        }
        int ans = cntC - 1;
        if (cntExtras >= ans) return ans;
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
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends