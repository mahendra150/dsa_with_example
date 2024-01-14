class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        unordered_map<int,int>dist;
        
        for(int i=1;i<=n;i++)dist[i]=INT_MAX;
        
            dist[k]=0;
        
            for(int i=0;i<n-1;i++){
                    for(auto i:times){
                        auto u=i[0];
                        auto v=i[1];
                        auto weight=i[2];
                        if(dist[u]==(INT_MAX))continue;
                        if(dist[u]+weight<dist[v])
                            dist[v]=dist[u]+weight;
                    }
            }
        
        int ans=0;
        for(auto i:dist ){
            ans=max(ans,i.second);
        }
        
        if(ans==INT_MAX)return -1;
        
        return ans;
        
        
    }
};