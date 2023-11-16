//https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

class TimeMap {
public:
    TimeMap() {
    }
    
    void set(std::string key, std::string value, int timestamp) {
        m_kvpairs.push_back(std::pair<std::string,std::string>(key, value));
        m_timeVec.push_back(timestamp);
    }
    
    std::string get(std::string key, int timestamp) {
        if (*m_timeVec.rbegin() < timestamp){
            return (*m_kvpairs.rbegin()).second;
        }
        int l=0,r=m_timeVec.size()-1;
        int k;
        while (l<=r){
            k = (l+r)/2;
            if (m_timeVec[k] == timestamp) return m_kvpairs[k].second;
            else if (m_timeVec[k] < timestamp) l = k+1;
            else r = k-1;
        }
        while (k<=0){
            if (m_kvpairs[k].first==key) return m_kvpairs[k].second;
            k--;
        }
        return "";
    }

    private:
        std::vector<std::pair<std::string,std::string>> m_kvpairs;
        std::vector<int> m_timeVec;

};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * std::string param_2 = obj->get(key,timestamp);
 */

int main(){
    // TimeMap* obj = new TimeMap();
    // obj->set("foo","bar",1);
    // std::cout<<obj->get("foo",1)<<'\n';
    // std::cout<<obj->get("foo",3)<<'\n';
    // obj->set("foo","bar2",4);
    // std::cout<<obj->get("foo",4)<<'\n';
    // std::cout<<obj->get("foo",5)<<'\n';

    TimeMap* obj = new TimeMap();
    obj->set("love","high",10);
    obj->set("love","low",20);
    std::cout<<obj->get("love",5)<<'\n';
    std::cout<<obj->get("love",10)<<'\n';
    std::cout<<obj->get("love",15)<<'\n';
    std::cout<<obj->get("love",20)<<'\n';
    std::cout<<obj->get("love",25)<<'\n';
} 
