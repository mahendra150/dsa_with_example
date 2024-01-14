class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>q;
    int size;
    KthLargest(int k, vector<int>& nums) {
        size=k;
        int n=nums.size();
        
        for(int i=0;i<n;i++)
        {
            if(q.size()<k)
            {
                q.push(nums[i]);
            }
            else
            {
                if(nums[i]>q.top())
                {
                    q.pop();
                    q.push(nums[i]);
                }
            }
        }
        
    }
    
    int add(int val) {
       if(q.size()<size)
       {
           q.push(val);
       }
    
        else  if(val>q.top())
        {
            q.pop();
            q.push(val);
        }
        return q.top();
        
        
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */