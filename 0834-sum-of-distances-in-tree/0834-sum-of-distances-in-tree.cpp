class Solution {
public:
   vector<vector<int>> h;
    vector<int> subtreeSize,ans,subtreeAns;
    
    Solution(){
        
         int mx= 3 * 1e4 +1;
        
        h.resize(mx);
        subtreeSize.resize(mx);
        ans.resize(mx);
        subtreeAns.resize(mx);
        
    }
    
     void preprocessing(int src,int par){
        
        int numOfNodes= 1;
        int ansForSubtree=0;
        
        for(int child: h[src]){
            
            if(child != par){
                
                 preprocessing(child,src);
                numOfNodes+= subtreeSize[child];
                ansForSubtree+= (subtreeSize[child] + subtreeAns[child] );
            }
        }
        
        subtreeSize[src]= numOfNodes;
        subtreeAns[src]= ansForSubtree;
    }
    
    void solve(int src,int par,int partial_ans,int totalNodes){
        
        ans[src]= subtreeAns[src] + (partial_ans + (totalNodes- subtreeSize[src]));
        
        for(int child: h[src]){
            
            if(child != par){
                
                solve(child,src, ans[src]-(subtreeAns[child] + subtreeSize[child]) ,totalNodes);
            }
        }
        
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        
        for(auto &node:edges){
            
            h[node[0]+1].push_back(node[1]+1);
            h[node[1]+1].push_back(node[0]+1);
        }
        
        preprocessing(1,0);
        
        solve(1, 0, 0, n);
        
        vector<int> res;
        
        for(int i=1;i<=n;i++){
            res.push_back(ans[i]);
        }
        
        return res;
        
        
    }
};