class NumArray {
public:
    //st-->segment tree
    //si-->segment index
    vector<int>st;
    int n;   //size of the (nums) vector
    
    void updateRangeSumUtility(int start,int end,int si,int index,int val){
        //base case
        if(index<start or index>end)return;
        
        if(start==end){
            if(index==start){
                st[si]=val;
            }
            return;
        }
        //recursive case
        int mid=start+ (end-start)/2;
        updateRangeSumUtility(start,mid,2*si+1,index,val);
        updateRangeSumUtility(mid+1,end,2*si+2,index,val);
        
        st[si]=st[2*si+1] + st[2*si+2];
        
    }
    
    int rangeSumUtility(int start,int end,int left,int right,int si){
        //Total overlap
        if(start>=left and end<=right)return st[si];
        
        //No overlap
        if(left>end or start>right)return 0;
        
        //Partial Overlap
        
        int mid=start+ (end-start)/2;
        return rangeSumUtility(start,mid,left,right,2*si+1)                            +rangeSumUtility(mid+1,end,left,right,2*si+2);
        
    }
    int buildTree(vector<int> &nums,int start,int end,int si){
        //base case
        if(start==end){
            st[si]=nums[start];
            return nums[start];
        }
        
        //recursive case
        int mid=start+ (end-start)/2;
        int left=buildTree(nums,start,mid,2*si+1);
        int right=buildTree(nums,mid+1,end,2*si+2);
        
        st[si]=left+right;
        return st[si];
    }
    NumArray(vector<int>& nums) {
      //  int n=nums.size();
        
        if(nums.size()>0){
        
        n=nums.size();
        st.resize(4*n,0);     //max size of (segment tree)
        int si=0;
        int start=0,end=n-1;
        buildTree(nums,start,end,si);
            
        }
        
    }
    
    void update(int index, int val) {
        
    //    int n=st.size();
        if(n==0)return;
        int start=0,end=n-1;
        int si=0;
        
        updateRangeSumUtility(start,end,si,index,val);
        
        
    }
    
    int sumRange(int left, int right) {
    //    int n=st.size();
        if(n==0)return 0;
        int si=0;
        int start=0,end=n-1;
        
      return  rangeSumUtility(start,end,left,right,si);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */