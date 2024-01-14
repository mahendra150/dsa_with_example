class Solution {
public:
    void makeGraph(vector<vector<int>> &graph,unordered_map<int,vector<int>> &h,vector<int> &outDegree,queue<int> &q){
        
        for(int i=0;i<graph.size();i++){
            for(int j=0;j<graph[i].size();j++){
                
                h[graph[i][j]].push_back(i);
            }
            outDegree[i]= graph[i].size();
            if(outDegree[i]==0)q.push(i);
        }
        
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n= graph.size();
        
        unordered_map<int,vector<int>> h;
        vector<int> outDegree(n,0);
        queue<int> q;
        
        //Creating abit different graph
        makeGraph(graph,h,outDegree,q);
        
        //Implementing Kahns Algorithm
        vector<int> ans;
        while(!q.empty()){
            
            auto node=q.front();
            q.pop();
            ans.push_back(node);
            
            for(auto incomingNode: h[node]){
                outDegree[incomingNode]--;
                if(!outDegree[incomingNode])q.push(incomingNode);
            }
            
        }
        
        sort(ans.begin(),ans.end());
        return ans;
    }
};