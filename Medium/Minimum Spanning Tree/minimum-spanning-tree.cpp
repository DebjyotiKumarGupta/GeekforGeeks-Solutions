//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends



class Solution
{
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
            parent[i] = size[i] = i;
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

    int spanningTree(int V, vector<vector<int>> adj[])
    {
       typedef pair<int,pair<int,int>> pd;
       vector<pd> v;
       for(int i=0;i<V;i++){
           for(auto it:adj[i]) v.push_back({it[1],{i,it[0]}});
       }
       sort(v.begin(),v.end());
       int mstwt=0;
       DisjointSet ds(V);
       for(auto it:v){
           int wt = it.first;
           int u = it.second.first;
           int v = it.second.second;
           
           if(ds.finduparent(u)!=ds.finduparent(v)){
               mstwt+= wt;
               ds.unionbyrank(u,v);
           }
       }
       return mstwt;
       
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends