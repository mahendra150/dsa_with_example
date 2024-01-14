class Solution {
public:
    bool topoSort(unordered_map<int,unordered_set<int>>&graph,vector<int>&ans){
        unordered_map<int,int>inDegree;
        
        for(auto i:graph){
            inDegree[i.first];
            for(auto nbr:i.second){
                inDegree[nbr]++;
            }
        }
        
        queue<int>q;
        
       for(auto i:inDegree){
           if(!i.second)q.push(i.first);
       }
        int count=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            
           ans[count++]=node;
            for(auto nbr:graph[node]){
                inDegree[nbr]--;
                if(inDegree[nbr]==0)q.push(nbr);
            }
        }
        
    //    for(auto i:inDegree){
    //        if(i.second)return false;
    //    }
   //     return true;
        
        return count==graph.size();
        
    }
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        
        for(int i=0;i<n;i++){
            if(group[i]== -1)group[i]=m++;
        }
        
        unordered_map<int,vector<int>>groupMap;
        
        for(int i=0;i<n;i++){
            groupMap[group[i]].push_back(i);
        }
        
        for(auto& i:groupMap){
            unordered_map<int,unordered_set<int>>graph;
            for(auto nbr:i.second){
                graph[nbr];
                for(auto prereq:beforeItems[nbr]){
                    if(group[nbr]==group[prereq]) graph[prereq].insert(nbr);
                }
            }
            
            if(!topoSort(graph,i.second))return {};
            
        }
        
        unordered_map<int,unordered_set<int>> groupGraph;
        
        for(int i=0;i<m;i++){
            groupGraph[i];
        }
        
        for(int i=0;i<n;i++){
            for(auto prereq:beforeItems[i]){
                if(group[i]!=group[prereq] and !groupGraph[group[prereq]].count(group[i]) ){
                    groupGraph[group[prereq]].insert(group[i]);
                }
            }
        }
        
        vector<int>output(m);
        
        if(!topoSort(groupGraph,output))return {};
        
        vector<int>finalAns;
        
        for(auto group:output){
            copy(groupMap[group].begin(),groupMap[group].end(),back_inserter(finalAns));
        }
        
        return finalAns;
        
        
        
        
    }
};