typedef pair<int,int> node;
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int n=arr.size();
        
        unordered_map<int,int>freq;
        
        for(auto it:arr){
            freq[it]++;
        }
        
        priority_queue<node,vector<node>,greater<node>> q;
        
        for(auto it:freq){
            q.push({it.second,it.first});
        }
        
        
        while(k--){
            
            auto val=q.top();
            q.pop();
            
            freq[val.second]--;
            if(freq[val.second])q.push({freq[val.second],val.second});
        }
        
        // while(!q.empty()){
        //     auto val=q.top();
        //     q.pop();
        //     cout<<val.second<<"-->"<<val.first<<endl;
        // }
        
       
        return q.size();
    }
};