class RandomizedCollection {
public:
    vector<pair<int,int>> nums;
    unordered_map<int,vector<int>> h;
    
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        
        auto address= h.find(val) == h.end();
            
            h[val].push_back(nums.size());
            nums.push_back(make_pair(val,h[val].size()-1));
            
        return address;
    }
    
    bool remove(int val) {
        
        auto address= h.find(val) != h.end();
        
        if(address){
            
            auto last=nums.back();
            auto indx= h[val].back();
            h[val].pop_back();
            h[last.first][last.second]=indx;
            nums[indx]= last;
            if(h[val].empty())h.erase(h.find(val));
            nums.pop_back();
            return true;
        }
        
        return false;
    }
    
    int getRandom() {
        
        return nums[rand()%nums.size()].first;
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */