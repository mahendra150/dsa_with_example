class Solution {
public:
    vector<int> res;
    vector<int> dfs(int node,unordered_map<int,vector<int>> &h,string &labels,unordered_map<int,bool> &visited){
        
        visited[node]= true;
        vector<int> count(26,0);
        
        for(auto nbr:h[node]){
            
            if(!visited[nbr]){
                
                vector<int> subRes= dfs(nbr,h,labels,visited);
                for(int i=0;i<26;i++){
                    
                    count[i]+= subRes[i];
                }
                
                // res[node]=max(res[node],subRes[labels[node]-65]);
            }
        }
        
        auto ch= labels[node];
        count[ch-97]+=1;
        
        res[node]+= count[ch-97];
       
        return count;
        
        
    }
    void makeGraph(vector<vector<int>> &edges,int n,unordered_map<int,vector<int>> &h){
        
        for(int i=0;i<edges.size();i++){
            
            h[edges[i][0]].push_back(edges[i][1]);
            h[edges[i][1]].push_back(edges[i][0]);
        }
        
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        
        unordered_map<int,vector<int>> h;
        makeGraph(edges,n,h);
        
        res.resize(n,0);
        unordered_map<int,bool> visited;
        for(int i=0;i<n;i++)visited[i]= false;
        
        dfs(0,h,labels,visited);
    
        
        return res;
    }
};