class Solution {
public:
    static bool comp(vector<double> &a,vector<double> &b){
        
        return a[0]<b[0];
    }
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n= quality.size();
        
        vector<vector<double>> workers;
        //  workers -->  {ratio,quality};
        
        for(int i=0;i<n;i++){
            
            workers.push_back({(double)(wage[i])/quality[i],(double)quality[i]});
        }
        
        sort(workers.begin(),workers.end(),comp);
        
        priority_queue<double> q;
        
        double res= DBL_MAX;
        double totalQuality= 0;
        
        for(int i=0;i<n;i++){
            auto ratio= workers[i][0];
            totalQuality+= workers[i][1];
            q.push(workers[i][1]);
            
            if(q.size()>k){
                
                totalQuality-= q.top();
                q.pop();
            }
            
            if(q.size()==k){
                
                auto cost= ratio*totalQuality;
                res=min(res,cost);
            }
        }
        
        return res;
        
    }
};