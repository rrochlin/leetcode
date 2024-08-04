//https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <unordered_map>

class TimeMap {
public:
    TimeMap() {
    }
   /* A much better way as shown below is to create a map of 
   timestamps and values. Each keys values will be sorted and you
   only need to worry about the value in each key for a binary search */ 
    
    void set(std::string key, std::string value, int timestamp) {
        m_kvpairs.push_back(std::pair<std::string,std::string>(key, value));
        m_timeVec.push_back(timestamp);
    }
    
    std::string get(std::string key, int timestamp) {
        if (*m_timeVec.begin() > timestamp) return "";
        int l=0,r=m_timeVec.size()-1;
        int k;
        while (l<=r){
            k = (l+r)/2;
            if (m_timeVec[k] == timestamp) {
                r=k;
                break;
            }
            else if (m_timeVec[k] < timestamp) l = k+1;
            else r = k-1;
        }
        while (r>=0){
            if (m_kvpairs[r].first==key) return m_kvpairs[r].second;
            r--;
        }
        return "";
    }

    private:
        std::vector<std::pair<std::string,std::string>> m_kvpairs;
        std::vector<int> m_timeVec;

};

class BetterTimeMap {
public:
    BetterTimeMap() {
        /*
        std::ios::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);
        */
    }
    
    void set(std::string key, std::string value, int timestamp) {
        stores[key].push_back({value, timestamp});
    }
    
    std::string get(std::string key, int timestamp) {
        if (stores.count(key) == 0) return std::string();

        const std::vector<std::pair<std::string, int>>& vec = stores[key];
        int size = vec.size();
        int l = 0, r = size - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            auto& p = vec[mid];
            if (p.second == timestamp) {
                return p.first;
            } else if (p.second > timestamp) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        // get lower_bound
        return (r >= 0) ? vec[r].first : ""; 
    }

private:
    std::unordered_map<std::string, std::vector<std::pair<std::string, int>>> stores;
};


int main(){
    // TimeMap* obj = new TimeMap();
    // obj->set("foo","bar",1);
    // std::cout<<"result:"<<obj->get("foo",1)<<'\n';
    // std::cout<<"result:"<<obj->get("foo",3)<<'\n';
    // obj->set("foo","bar2",4);
    // std::cout<<"result:"<<obj->get("foo",4)<<'\n';
    // std::cout<<"result:"<<obj->get("foo",5)<<'\n';

    TimeMap* obj = new TimeMap();
    obj->set("love","high",10);
    obj->set("love","low",20);
    std::cout<<"result:"<<obj->get("love",5)<<'\n';
    std::cout<<"result:"<<obj->get("love",10)<<'\n';
    std::cout<<"result:"<<obj->get("love",15)<<'\n';
    std::cout<<"result:"<<obj->get("love",20)<<'\n';
    std::cout<<"result:"<<obj->get("love",25)<<'\n';
} 
