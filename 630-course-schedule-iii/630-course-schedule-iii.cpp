class Solution {
public:
    static bool comp(vector<int>&a,vector<int>&b){
        return a[1]<b[1];
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        
        sort(courses.begin(),courses.end(),comp);
        
        priority_queue<int>q;
        int currTime=0;
        
        for(auto i:courses){
            auto duration=i[0];
            auto lastDay=i[1];
            
            q.push(duration);
            currTime+=duration;
            
            if(currTime>lastDay){
                currTime-=q.top();
                q.pop();
            }
        }
        
        return q.size();
        
    }
};