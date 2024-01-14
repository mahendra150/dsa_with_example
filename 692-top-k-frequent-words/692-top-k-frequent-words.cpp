typedef pair<int,string>node;
class Solution {
public:
    static bool comp(node &a,node &b){
        if(a.first==b.first)return a.second<b.second;
        
        return a.first>b.first;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        unordered_map<string,int>freq;
        
        int n=words.size();
        
        for(int i=0;i<n;i++)freq[words[i]]++;
        
        priority_queue<node>q;
        
        for(auto i:freq){
            q.push({i.second,i.first});
        }
        
        vector<node>curr_ans;
        
        while(!q.empty()){
            curr_ans.push_back(q.top());
            q.pop();
        }
        
        sort(curr_ans.begin(),curr_ans.end(),comp);
        
        vector<string>ans(k,"");
        
       for(int i=0;i<k;i++){
           ans[i]=curr_ans[i].second;
       }
        
        return ans;
        

    }
    
};