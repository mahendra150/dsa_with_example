typedef pair<int,pair<int,int>>node;
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int mi=INT_MAX;
        int mx=INT_MIN;
        int finalMin=INT_MAX;
        int finalMax=INT_MIN;
        
        
        priority_queue<node,vector<node>,greater<node>>q;
        int n=nums.size();
        
        for(int i=0;i<n;i++){
            q.push({nums[i][0],{i,0}});
            mi=min(mi,nums[i][0]);
            mx=max(mx,nums[i][0]);
        }
        finalMin=mi;
        finalMax=mx;
        
        while(!q.empty()){
            auto val=q.top();
            q.pop();
            int row=val.second.first;
            int col=val.second.second;
            mi=val.first;
            if(mx-mi<finalMax-finalMin){
                finalMax=mx;
                finalMin=mi;
            }
            if(col+1<nums[row].size()){
                mx=max(mx,nums[row][col+1]);
                q.push({nums[row][col+1],{row,col+1}});
            } 
            else break;
               
        }
        
        return {finalMin,finalMax};
        
        
        
    }
};