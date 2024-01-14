class medianFinder {
public:
    multiset<int>left;
    multiset<int>right;
    
    void balance(){
        if(right.size()>left.size()){
            auto val= *(right.begin());
            auto address=right.find(val);
            if(address != right.end())right.erase(address);
            left.insert(val);
        }
        else if(left.size()-right.size()>1){
            auto val= *(left.rbegin());
            auto address=left.find(val);
            if(address != left.end())left.erase(address);
            right.insert(val);
        }
    }
    double findMedian(){
        if(left.size()==right.size())return (double(*(left.rbegin())) + double(*(right.begin())))/2;
        else return double(*(left.rbegin()));
    }
    void addNum(int num){
        if(left.size()==0 or num< *(left.rbegin()))left.insert(num);
        else right.insert(num);
        balance();
    }
    void deleteNum(int num){
        auto addressLeft=left.find(num);
        auto addressRight=right.find(num);
        if(addressLeft != left.end())left.erase(addressLeft);
        else right.erase(addressRight);
        
        balance();
    }
    
    
};
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<double>ans;
        
        medianFinder m;
        
        for(int i=0;i<k;i++)m.addNum(nums[i]);
        
        for(int i=k;i<n;i++){
            ans.push_back(m.findMedian());
            m.addNum(nums[i]);
            m.deleteNum(nums[i-k]);
        }
        ans.push_back(m.findMedian());
        
        return ans;
        
    }
};