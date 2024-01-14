class Solution {
public:
    double res;
void makeGraph(int n,unordered_map<int,vector<pair<int,double>>> &h,vector<vector<int>> &edges, vector<double> &prob){
        
        for(int i=0;i<edges.size();i++){
            
            h[edges[i][0]].push_back({edges[i][1],prob[i]});
            h[edges[i][1]].push_back({edges[i][0],prob[i]});
        }
    
    }
    
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        
        unordered_map<int,vector<pair<int,double>>> h;
        makeGraph(n,h,edges,succProb);
        
        
        unordered_map<int,double> dist;
        for(int i=0;i<n;i++){
            
            dist[i]= 0;
        }
        
        
        dist[start_node]= 1;
        set<pair<double,int>> s;
        
        s.insert({1,start_node});
        
       while(!s.empty()){
           
           auto node= *(s.rbegin());
           auto parent= node.second;
           auto parent_dist= node.first;
           
           auto address= s.find(node);
           if(address != s.end())s.erase(address);
           
           for(auto nbr:h[parent]){
               
               auto bacha= nbr.first;
               auto bp_dist= nbr.second;
               
               if(dist[bacha] != 0){
                   
                   if(parent_dist*bp_dist> dist[bacha]){
                       
                       auto address= s.find({dist[bacha],bacha});
                       if(address != s.end()){
                           
                        s.erase(address);
                       dist[bacha]= parent_dist*bp_dist;
                       s.insert({dist[bacha],bacha});
                       }
                   }
               }
               else{
                   
                  dist[bacha]= parent_dist*bp_dist;
                  s.insert({dist[bacha],bacha});
               }
               
           }
       }
        
        
        return dist[end_node];
    }
};