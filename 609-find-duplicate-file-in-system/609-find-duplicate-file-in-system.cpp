class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string,vector<string>>h;
        
        for(auto path:paths){
            stringstream ss(path);
            
            string dir;
            string file;
            
            getline(ss,dir,' ');
            
            while(getline(ss,file,' ')){
                string content=file.substr(file.find('(')+1,file.find(')')-file.find('(')-1);
                string fileName=dir + '/' + file.substr(0,file.find('('));
                h[content].push_back(fileName);
                
            }
        }
        
        vector<vector<string>>res;
        
        for(auto i:h){
            if(i.second.size()>1){
                vector<string>subRes;
                for(auto file:i.second){
                    subRes.push_back(file);
                }
                
                res.push_back(subRes);
            }
        }
        
        return res;
        
    }
};