class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int>need;
        
        for(auto ch:s){
            
            need[ch]+=1;
        }
        
        string res= "";
        
        for(int i=0;i<order.length();i++){
            
            auto ch=order[i];
            if(need.count(ch)){
                
                while(need[ch]){
                    
                    res+=ch;
                    need[ch]-=1;
                    if(!need[ch])need.erase(need.find(ch));
                }
            }
        }
        
        for(auto ch:need){
            
            while(ch.second){
                
                res+=ch.first;
                ch.second-=1;
            }
        }
        
        return res;
        
    }
};