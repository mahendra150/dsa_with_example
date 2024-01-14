// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        unordered_map<int,int>dist;
        set<pair<int,int>>s;
       for(int i=0;i<V;i++)dist[i]=INT_MAX;
        int src=S;
        dist[src]=0;
        s.insert({0,src});
        while(!s.empty())
        {
            auto p= *(s.begin());
            s.erase(s.begin());
            auto parent_dist=p.first;
            auto parent=p.second;
            for(auto nbr:adj[parent])
            {
                auto bacha=nbr[0];
                    int bp_dist=nbr[1];
                if(dist[bacha]!=INT_MAX)
                {
                    if(parent_dist+bp_dist<dist[bacha])
                    {
                        auto address=s.find({dist[bacha],bacha});
                        if(address != s.end())
                        {
                            s.erase(address);
                            dist[bacha]=parent_dist + bp_dist;
                            s.insert({dist[bacha],bacha});
                        }
                    }
                }
                else
                {
                    dist[bacha]=parent_dist + bp_dist;
                    s.insert({dist[bacha],bacha});
                }
            }
        }
        vector<int>ans;
        for(int i=0;i<V;i++)
        {
            ans.push_back(dist[i]);
        }
        return ans;
        
    }
};


// { Driver Code Starts.


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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends