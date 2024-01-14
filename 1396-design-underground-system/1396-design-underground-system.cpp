class UndergroundSystem {
public:
    unordered_map<int,pair<string,int>> checkInMap;   // id -> {startStaion,startTime};
    unordered_map<string,pair<double,int>> routeMap;  // routeName -> {totalTime,count};
    
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        
        checkInMap[id]= {stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto checkIn= checkInMap[id];
        auto address= checkInMap.find(id);
        if(address != checkInMap.end())checkInMap.erase(address);
        
        auto startStation= checkIn.first;
        auto startTime= checkIn.second;
        
        auto endStation= stationName;
        auto endTime= t;
        
        auto routeName= startStation + "_" + endStation;
        auto totalTime= endTime-startTime;
        
        routeMap[routeName].first+= totalTime;
        routeMap[routeName].second+= 1;
        
    }
    
    double getAverageTime(string startStation, string endStation) {
        
        auto routeName= startStation + "_" + endStation;
        
        auto totalTime= routeMap[routeName].first;
        auto count= routeMap[routeName].second;
        
        return totalTime/count;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */