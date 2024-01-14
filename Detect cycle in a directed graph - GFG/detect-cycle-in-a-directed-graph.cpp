// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(int node,unordered_map<int,bool>&visited,unordered_map<int,bool>&path,vector<int> adj[])
    {
        visited[node]=true;
        path[node]=true;
        for(auto nbr:adj[node])
        {
            if(!visited[nbr])
            {
                if(dfs(nbr,visited,path,adj))
                {
                    return true;
                }
            }
            else if(path[nbr]==true)
            {
                return true;
            }
        }
        path[node]=false;
        return false;
    }    
    bool isCyclic(int V, vector<int> adj[]) {
        
        // code here
        unordered_map<int,bool>visited;
        unordered_map<int,bool>path;
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                if(dfs(i,visited,path,adj))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends