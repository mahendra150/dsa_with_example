class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        int n=s.length();
        
        unordered_map<int,pair<int,string>>h;
        
        for(int i=0;i<indices.size();i++){
            if(s.substr(indices[i],sources[i].length())==sources[i]){
                h[indices[i]]=make_pair(sources[i].length(),targets[i]);
            }
        }
        
        string res="";
        for(int i=0;i<n;i++){
            if(h.find(i) != h.end()){
                res+=h[i].second;
                i+=h[i].first-1;
            }
            else res+=s[i];
        }
        
        return res;
        
    }
};