class Solution {
public:
    void makeGraph(vector<vector<int>>& edges,unordered_map<int,vector<int>>&h,vector<int>&degree){
        for(auto i:edges){
            h[i[0]].push_back(i[1]);
            h[i[1]].push_back(i[0]);
            degree[i[0]]++;
            degree[i[1]]++;
        }
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1)return{0};
        
        unordered_map<int,vector<int>>h;
        vector<int>degree(n,0);
        
        makeGraph(edges,h,degree);
        
        
        
        queue<int>q;
        
        for(int i=0;i<n;i++)if(degree[i]==1)q.push(i);
        
        vector<int>ans;
        while(!q.empty()){
            ans.clear();
            int n=q.size();
            while(n--){
                auto node=q.front();
                q.pop();
                for(auto nbr:h[node]){
                    degree[nbr]--;
                    if(degree[nbr]==1)q.push(nbr);
                }
                ans.push_back(node); 
            }
        }
        return ans;
        
        
    }
};