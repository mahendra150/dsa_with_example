// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    // Code here
	    unordered_map<int,int>dist;
	    for(int i=0;i<n;i++)dist[i]=INT_MAX;
	    dist[0]=0;
	    for(int i=0;i<n-1;i++)
	    {
	       for(int node=0;node<edges.size();node++)
	        {
	           auto u=edges[node][0];
	            auto v=edges[node][1];
	            auto weight=edges[node][2];
	            if(dist[u]==INT_MAX)continue;
	            if(dist[u]+weight<dist[v])dist[v]=dist[u]+weight;
	            
	            
	        }
	    }
	     for(int node=0;node<edges.size();node++)
	        {
	           auto u=edges[node][0];
	            auto v=edges[node][1];
	            auto weight=edges[node][2];
	           
	            if(dist[u]+weight<dist[v])return 1;
	            
	            
	        }
	        return 0;
	    
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends