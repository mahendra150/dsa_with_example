// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
     unordered_map<int,list<int>>h;
	public:
	void dfs(int node,vector<bool>&visited,vector<int>h[])
	{
	    visited[node]=true;
	    for(auto nbr:h[node])
	    {
	        if(!visited[nbr])dfs(nbr,visited,h);
	    }
	}
	void topo(int node,int V,vector<int> adj[],vector<bool>&visited,stack<int>&s)
	{
	    visited[node]=true;
	    for(auto nbr:adj[node])
	    {
	        if(!visited[nbr])topo(nbr,V,adj,visited,s);
	    }
	    s.push(node);
	}
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        //code here
       vector<bool>visited(V,false);
       stack<int>s;
       
       //Step 1:Topo Sort
       for(int i=0;i<V;i++)
       {
           if(!visited[i])topo(i,V,adj,visited,s);
       }
       
       //Step 2: Transpose the graph ,basically reverse all the directions
        vector<int>h[V];
       for(int i=0;i<V;i++)
      { auto node=i;
           visited[node]=false;
           for(auto nbr:adj[node])h[nbr].push_back(node);
       }
       
       //Step 3: Traverse the nodes in the stack
       int scc=0;
       while(!s.empty())
       {
           int node=s.top();
           s.pop();
           if(!visited[node])
           {
               dfs(node,visited,h);
               scc++;
           }
       }
       return scc;
       
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends