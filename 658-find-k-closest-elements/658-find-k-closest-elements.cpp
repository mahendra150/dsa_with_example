typedef pair<int,int>node;
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        
        priority_queue<node>q;
        
        for(int i=0;i<n;i++){
            int val=abs(arr[i]-x);
            if(q.size()<k)q.push({val,arr[i]});
            else{
                if(val<q.top().first){
                    q.pop();
                    q.push({val,arr[i]});
                }
            }
        }
        
        vector<int>ans;
        
        while(!q.empty()){
            ans.push_back(q.top().second);
            q.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};