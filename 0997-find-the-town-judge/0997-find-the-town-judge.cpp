class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        vector<int> inDegree(n+1,0);
        vector<int> outDegree(n+1,0);
        
        for(int i=0;i<trust.size();i++){
            outDegree[trust[i][0]]+=1;
            inDegree[trust[i][1]]+=1;
        }
        
        int ans=(-1);
        for(int i=1;i<=n;i++){
            if(inDegree[i]-outDegree[i]==(n-1)){
                ans=i;
            }
        }
        
        return ans;
        
    }
};