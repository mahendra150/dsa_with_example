struct comp{
    bool operator() (const pair<int,int> &a,const pair<int,int> &b) const{
        if(a.first==b.first)
            return a.second<b.second;        
        return a.first>b.first;
    }
};
class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        
        unordered_map<int,vector<pair<int,int>>> h;
        
        for(auto node:edges){
            
            auto count= node[2];
            h[node[0]].push_back({node[1],count+1});
            h[node[1]].push_back({node[0],count+1});
        }
        
        set<pair<int,int>,comp> s;
        unordered_map<int,int> dist;
        
       for(int i=0;i<n;i++)dist[i]= (-1);
        
        dist[0]= maxMoves;
        
        s.insert({dist[0],0});
        
        while(!s.empty()){
            
            auto node= *(s.begin());
            auto address= s.find(node);
            if(address != s.end())s.erase(address);  
            
            auto parent_dist= node.first;
            auto parent= node.second;
            
            for(auto nbr:h[parent]){
                
                auto bacha= nbr.first;
                auto bp_dist= nbr.second;
                
                if(dist[bacha] != (-1)){
                    
                    if(parent_dist-bp_dist > dist[bacha]){
                       
                        auto address= s.find({dist[bacha],bacha});
                        if(address != s.end()){
                            
                            s.erase(address);
                             dist[bacha]= parent_dist-bp_dist;
                            s.insert({dist[bacha],bacha});
                        }
                    }
                }
                
                else{
                  dist[bacha]= parent_dist-bp_dist;
                    s.insert({dist[bacha],bacha});
                }
            }
            
        }
        
        int res=0;
        // Counting Bigger Nodes
        for(int i=0;i<n;i++){
            if(dist[i]>=0)res+=1;
        }
        
        //Counting SubNodes
        for(auto node:edges){
            auto x= node[0];
            auto y= node[1];
            auto subNodes= node[2];
            
            auto wx= max(0,dist[x]);
            auto wy= max(0,dist[y]);
            auto capture= wx+wy;
            
            res+= min(subNodes,capture);
        }
        
        return res;
        
    }
};