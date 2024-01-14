typedef pair<int,int> node;
class Solution {
public:
    static bool comp(node &a,node &b){
        return a.second<b.second;
    }
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n=profits.size();
        
        vector<node>nums;
        for(int i=0;i<n;i++){
            nums.push_back({profits[i],capital[i]});
        }
        
        sort(nums.begin(),nums.end(),comp);
        priority_queue<int>q;
        
        int i=0;
        while(k--){
            
            while(i<n and w>=nums[i].second){
                q.push(nums[i].first);
                i+=1;
            }
            
            if(!q.empty()){
                w+= q.top();
                q.pop();
            }
        }
        
        return w;
        
        
    }
};