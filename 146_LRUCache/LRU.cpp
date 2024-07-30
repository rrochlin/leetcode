#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
class LRUCache {
public:
    LRUCache(int capacity) {
        m_capacity = capacity;
    }

    int get(int key) {
        auto el = m_cache.find(key);
        if (el == m_cache.end()) return -1;
        return el->second;
    }

    void put(int key, int value) {
        if (m_capacity>0) {
            m_capacity--;
            m_cache[key] = value;
        }

    }
private:
    int m_capacity;
    std::unordered_map<int, int> m_cache;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

// ["LRUCache","put","put","get","put","get","put","get","get","get"]
// [[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]
int main(){
    std::string ins[] =  {"LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"};
    int nums[][2] = {{2},{1,1},{2,2},{1},{3,3},{2},{4,4},{1},{3},{4}};
    int j = 0;
    LRUCache* obj;
    int param_1;
    for (std::string i : ins){
        if(i=="LRUCache"){
            obj = new LRUCache(nums[j][0]);
            std::cout<<"null ";
        }
        else if (i == "get"){
            param_1 = obj->get(nums[j][0]);
            std::cout<<param_1;
        }
        else if (i == "put"){
            obj->put(nums[j][0], nums[j][1]);
            std::cout<<"null ";
        }
    }
    delete obj;
};