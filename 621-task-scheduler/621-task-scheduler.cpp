typedef pair<int,char>node;
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        unordered_map<char,int>freq;
        
        int m=tasks.size();
        for(int i=0;i<m;i++)freq[tasks[i]]++;
        
        priority_queue<node>q;
        for(auto i:freq)q.push({i.second,i.first});
       int totalTime=0;
        int cycles=n+1;
        while(!q.empty()){
            int time=0;
            unordered_map<char,int>temp;
            for(int i=0;i<=n;i++){
                if(!q.empty()){
                    
                auto val=q.top();
                val.first--;
                temp[val.second]=val.first;
                q.pop();
                time+=1;
                }
                
            }
            
            for(auto it:temp){
                if(it.second)q.push({it.second,it.first});
            }
            totalTime+=(!q.empty())?cycles:time;
        }
        return totalTime;
    }
};