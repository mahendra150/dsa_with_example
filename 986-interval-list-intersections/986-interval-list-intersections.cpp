class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        
        int n=firstList.size();
        int m=secondList.size();
        
        int i=0,j=0;
        vector<vector<int>>ans;
        while(i<n and j<m)
        {
          int  startTime=max(firstList[i][0],secondList[j][0]);
            int endTime=min(firstList[i][1],secondList[j][1]);
            
            if(startTime<=endTime)
            {
                vector<int>curr_ans;
                curr_ans.push_back(startTime);
                curr_ans.push_back(endTime);
                ans.push_back(curr_ans);
                curr_ans.clear();
            }
            if(firstList[i][1]<secondList[j][1])i++;
            else j++;
            
        }
        return ans;
        
    }
};