class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int length=s.length();
        int n=words.size();
        int len=words[0].length();
        int window=n*len;
        unordered_map<string,int>need;
        //need map->to keep the needed freq
        
        for(auto word:words)need[word]++;
        
        vector<int>ans;
        
        for(int i=0;i<=length-window;i++){
            int index=i;
            int count=n;
            unordered_map<string,int>valid;
            //valid map->window freq
                //I am checking the window from here
            while(count){
                auto str=s.substr(index,len);
                valid[str]++;
                if(need.count(str)>0 and valid[str]<=need[str]){
                    count--;
                    index+=len;
                }
                else break;
                
            }
            if(count==0)ans.push_back(i);
        }
        
        return ans;
        
    }
};