typedef vector<int> node;
class Solution {
public:
    vector<int> nextState(vector<int> &nums){
        
        vector<int> next(8);
        for(int i=1;i<7;i++){
            
            next[i]= (nums[i-1]==nums[i+1]);
        }
        
        return next;
    }
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        int len= cells.size();
        
        set<node> st;
        int cycle=0;
        
        while(n--){
            
            auto next= nextState(cells);
            
            auto val= cells;
            if(st.find(next) != st.end()){
                
                n%= cycle;
            }
            else st.insert(next);
            cycle+= 1;
            
            cells= next;
    }
        
        return cells;
    }
};