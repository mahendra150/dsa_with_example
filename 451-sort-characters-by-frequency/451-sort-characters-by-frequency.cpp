class Solution {
public:
    typedef pair<int,char>node;
    string frequencySort(string s) {
        unordered_map<char,int>freq;
        
        for(int i=0;i<s.length();i++)freq[s[i]]++;
        
        priority_queue<node>q;
        
        for(auto i:freq)q.push({i.second,i.first});
        
        string res="";
        while(!q.empty()){
            auto val=q.top();
            while(freq[val.second]){
                res+=val.second;
                freq[val.second]--;
            }
            q.pop();
        }
        
        return res;
        
    }
};