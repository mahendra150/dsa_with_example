class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        
        
        int steps=0;
        unordered_set<string> valid(bank.begin(),bank.end());
        
        queue<string> q;
        q.push(startGene);
        
        while(!q.empty()){
            
            int n=q.size();
            while(n--){
                
                auto word= q.front();
                q.pop();
                if(word==endGene)return steps;
                for(int i=0;i<8;i++){
                    
                    auto ch= word[i];
                    
                    word[i]='A';
                    if(valid.count(word)){
                        
                        q.push(word);
                        valid.erase(valid.find(word));
                    }
                    
                    word[i]='C';
                    if(valid.count(word)){
                        
                        q.push(word);
                        valid.erase(valid.find(word));
                    }
                    
                     word[i]='G';
                    if(valid.count(word)){
                        
                        q.push(word);
                        valid.erase(valid.find(word));
                    }
                    
                    word[i]='T';
                    if(valid.count(word)){
                        
                        q.push(word);
                        valid.erase(valid.find(word));
                    }
                    
                    word[i]= ch;
                }
            }
            steps+=1;
        }
        
        return (-1);
    }
};