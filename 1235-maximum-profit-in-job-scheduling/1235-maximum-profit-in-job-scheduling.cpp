class Solution {
private:
    struct interval{
        int st;
        int en;
        int profit;
    };
    vector<interval>nums;
    vector<int>dp;
    
    static bool comp(struct interval &a,struct interval &b){
        return a.st<b.st;
    }
    
    int customLowerBound(int indx){
        int n=nums.size();
        int start=indx+1;
        int end=n-1;
        int ans=(-1);
        
        while(start<=end){
            int mid= end +(start-end)/2;
            
            if(nums[mid].st<nums[indx].en){
                start=mid+1;
            }
            else{
                ans=mid;
                end=mid-1;
            }
        }
        
        return ans;
    }
    int utility(int indx){
        
        if(indx>=nums.size())return 0;
        
        if(dp[indx]!=(-1))return dp[indx];
        
        
        
        int nextIntervalIndx=customLowerBound(indx);
        //Exclusion Step
        int exclude=0 + utility(indx+1);
        
        //inclusion Step
        int include=nums[indx].profit+ (nextIntervalIndx==(-1)?0:utility(nextIntervalIndx));
        
        return dp[indx]=max(exclude,include);
        
    }
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=startTime.size();
        nums.resize(n);
        dp.resize(n+1,-1);
        
        for(int i=0;i<n;i++){
            nums[i].st=startTime[i];
            nums[i].en=endTime[i];
            nums[i].profit=profit[i];
        }
        
        sort(nums.begin(),nums.end(),comp);
        
        int indx=0;
        return  utility(indx);
        
        
        
    }
};