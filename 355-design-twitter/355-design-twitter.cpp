typedef pair<int,int>node;
class Twitter {
public:
    unordered_map<int,set<int>>followerMap;
//    unordered_map<int,vector<int>>tweetMap;
    vector<node>newsFeed;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
      //  tweetMap[userId].push_back(tweetId);
        newsFeed.push_back({tweetId,userId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int>ans;
        vector<node>temp;
        while(newsFeed.size()>0 and ans.size()<10){
            auto val=newsFeed.back();
            newsFeed.pop_back();
            temp.push_back(val);
            auto checkFollowing=val.second;
            if(followerMap[userId].count(checkFollowing)>0 or userId==checkFollowing)
                ans.push_back(val.first);
            else continue;
            
        }
     //   for(auto i:tweetMap){
      //      for(auto x:i.second)newsFeed.push_back({x,i.first});
    //    }
        
        while(temp.size()>0){
            newsFeed.push_back(temp.back());
            temp.pop_back();
        }
        
        return ans;
        
    }
    
    void follow(int followerId, int followeeId) {
        followerMap[followerId].insert(followeeId);
        
    }
    
    void unfollow(int followerId, int followeeId) {
        auto address=followerMap[followerId].find(followeeId);
        if(address != followerMap[followerId].end())followerMap[followerId].erase(followeeId);
        
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */