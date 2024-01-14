class Solution {
public:
    vector<string> utility(string &node){
        vector<string> res;
        for(int i=0;i<4;i++){
            
            auto temp= node;
            temp[i]=(node[i]-'0'+1)%10 + '0';
            res.push_back(temp);
            temp[i]=(node[i]-'0'-1+10)%10 + '0';
            res.push_back(temp);
        }
        
        return res;
    }
    int openLock(vector<string>& deadends, string target) {
        
        unordered_set<string> q1,q2,visited;
        unordered_set<string> restricted(deadends.begin(),deadends.end());
        unordered_set<string> pass;
        
        auto source="0000";
        if(restricted.count(target) or restricted.count(source))return -1;
        if(source==target)return 0;
        
        visited.insert(source);
        visited.insert(target);
        q1.insert(source);
        q2.insert(target);
        
        int res=0;
        while(!q1.empty() and !q2.empty()){
            
            if(q1.size()>q2.size())swap(q1,q2);
            pass.clear();
                
            for(auto node:q1){
                auto neighbours= utility(node);
                for(auto nbr:neighbours){
                    
                    if(q2.find(nbr) != q2.end())return res+1;
                    if(!visited.count(nbr) and !restricted.count(nbr)){
                        
                        pass.insert(nbr);
                    }
                }
            }
            
            swap(q1,pass);
            res+=1;
        }
        
        return -1;
        
    }
};