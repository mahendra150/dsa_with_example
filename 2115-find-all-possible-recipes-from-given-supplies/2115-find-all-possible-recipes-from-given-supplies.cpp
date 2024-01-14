class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n=  recipes.size();
        
        unordered_map<string,vector<string>> h;
        unordered_map<string,int> inDegree;
        unordered_set<string> st(supplies.begin(),supplies.end());
        
        for(int i=0;i<n;i++)inDegree[recipes[i]]=0;
        
        for(int i=0;i<n;i++){
            
            for(int j=0;j<ingredients[i].size();j++){
                
                if(!st.count(ingredients[i][j])){
                    
                    h[ingredients[i][j]].push_back(recipes[i]);
                    inDegree[recipes[i]]+=1;
                }
            }
        }
        
        vector<string> res;
        queue<string> q;
        
        for(auto i:inDegree){
            
            if(!i.second){
                
                q.push(i.first);
            }
        }
        
        while(!q.empty()){
            
            auto node= q.front();
            q.pop();
            
            res.push_back(node);
            
            for(auto nbr: h[node]){
                
                inDegree[nbr]-=1;
                if(!inDegree[nbr])q.push(nbr);
            }
        }
        
        return res;
    }
};