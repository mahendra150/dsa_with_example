struct segmentTree{
    vector<long long int>u;
    
    vector<int>st;
    int  n;
    
    void updateRangeSum(int start,int end,int si,int index){
        //base case
        if(start==end){
            if(index==start){
            st[si]=0;
            return;
            }
        }
        //recursive case
        
        int mid=start + (end-start)/2;
        
        if(index<=mid){
            updateRangeSum(start,mid,2*si,index);
        }
        else{
           updateRangeSum(mid+1,end,2*si+1,index);
        }
        
        st[si]=st[2*si] + st[2*si+1];
        return;
        
    }
    int rangeSum(int start,int end,int si,long long int lower,long long int upper){
        //Total Overlap
        if(u[start]>= lower and u[end]<=upper)return st[si];
        
        //No Overlap
        if(u[end]<lower or u[start]>upper)return 0;
        
        
        //Partial Overlap
        int mid=start + (end-start)/2;
        
        int left=rangeSum(start,mid,2*si,lower,upper);
        int right=rangeSum(mid+1,end,2*si+1,lower,upper);
        
        return left+right;
        
    }
    int buildTree(vector<long long int> &v,int start,int end,int si){
        //base case
        if(start==end){
            st[si]=1;
            return st[si];
        }
        //recursive case
        int mid=start + (end-start)/2;
        
        int left=buildTree(v,start,mid,2*si);
        int right=buildTree(v,mid+1,end,2*si+1);
        
        st[si]=left+right;
        return st[si];
    }
    segmentTree(vector<long long int> &v){
        n=v.size();
        st.resize(4*n,0);
        u.resize(n,0);
        
        
        int start=0,end=n-1;
        int si=1;
        buildTree(v,start,end,si);
        
        for(int i=0;i<n;i++)u[i]=v[i];
    }
};
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n=nums.size();
        
        vector<pair<long long int,int>>v;
        v.push_back(make_pair(nums[0],0));
        
        for(int i=1;i<n;i++){
            v.push_back(make_pair(v.back().first+nums[i],i));
        }
        
        sort(v.begin(),v.end());
        vector<long long int>u(n,0);
        unordered_map<int,int>uMap;
        
        for(int i=0;i<n;i++){
            u[i]=v[i].first;
            uMap[v[i].second]=i;
        }
        
        segmentTree sgTree(u);
        
        long long int Lower=lower;
        long long int Upper=upper;
        int count=0;
        
        for(int i=0;i<n;i++){
            count+=sgTree.rangeSum(0,n-1,1,Lower,Upper);
            Lower+=nums[i];
            Upper+=nums[i];
            sgTree.updateRangeSum(0,n-1,1,uMap[i]);
        }
        
        return count;
    }
};