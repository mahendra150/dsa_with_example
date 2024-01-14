class TimeMap {
public:
   unordered_map<string,vector<pair<string,int>>>h;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
      h[key].push_back({value,timestamp});
        
    }
    
    string get(string key, int timestamp) {
        
        if(!h.count(key))return "";
        
        int s=0;
        int e=h[key].size()-1;
        
        while(s<=e){
            int mid=e+(s-e)/2;
            if(timestamp>h[key][mid].second)s=mid+1;
            else if(timestamp<h[key][mid].second)e=mid-1;
            else if(timestamp==h[key][mid].second)return h[key][mid].first;
        }
        
       if(e>=0) return h[key][e].first;
        
        return "";
        
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */