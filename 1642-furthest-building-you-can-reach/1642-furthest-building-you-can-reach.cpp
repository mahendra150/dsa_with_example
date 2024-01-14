class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n= heights.size();
        
        priority_queue<int> q;
        
        int i=0;
        for(i;i<n-1;i++){
            if(heights[i]>=heights[i+1])continue;
            
            int diff= heights[i+1] - heights[i];
            
            if(bricks>=diff){
                
                bricks-=diff;
                q.push(diff);
            }
            else if(ladders>0){
                
                if(!q.empty()){
                    
                    auto maxBricksPast= q.top();
                    if(maxBricksPast>diff){
                        
                        q.pop();
                        bricks+= maxBricksPast;
                        bricks-=diff;
                        q.push(diff);
                    }
                }
                
                ladders-=1;
            }
            
            else break;
        }
        
        return i;
        
    }
};