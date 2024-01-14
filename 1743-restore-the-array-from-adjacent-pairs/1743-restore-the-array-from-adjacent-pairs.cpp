class Solution {
public:
    void dfs(int node,unordered_map<int,vector<int>> &h,unordered_map<int,bool> &visited,vector<int> &res){
        visited[node]= true;
        res.push_back(node);
        
        for(auto nbr:h[node]){
            
            if(!visited[nbr]){
                dfs(nbr,h,visited,res);
            }
        }
        
    }
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        int n= adjacentPairs.size();
        
        unordered_map<int,vector<int>> h;
        
        for(auto i:adjacentPairs){
            
            h[i[0]].push_back(i[1]);
            h[i[1]].push_back(i[0]);
        }
        
//         for(auto i:h){
            
//             cout<<i.first<<"-->";
//             for(auto nbr:i.second){
                
//                 cout<<nbr<<" ";
//             }
//             cout<<endl;
//         }
        
        unordered_map<int,bool> visited;
        vector<int> res;
        
        for(auto i:h){
            
            if(i.second.size()==1){
                
                dfs(i.first,h,visited,res);
                return res;
            }
        }
        
        return {};
    }
};