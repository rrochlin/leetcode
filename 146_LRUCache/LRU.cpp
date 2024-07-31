#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include "file_reader.h"

struct MyListNode {
    int key;
    int val;
    MyListNode *next;
    MyListNode *prev;
    MyListNode() : key(-1) {}
    MyListNode(int x) : key(x) {}
    MyListNode(int x, int y) : key(x), val(y) {}
    MyListNode(int x, int y, MyListNode* prev) : key(x), val(y), prev(prev) {}
    MyListNode(int x, int y, MyListNode* prev, MyListNode* next) : key(x), val(y), prev(prev), next(next) {}
};

class LRUCache {
public:
    LRUCache(int capacity) {
        m_capacity = capacity+1;
        tail = new MyListNode(-1);
        head = tail;
        m_cache[-1] = tail;
        head->prev = tail;
        tail->next = head;
    }

    void set_head(MyListNode* temp){
        if (head==temp) return;
        if (tail==temp) tail = temp->next;
        else temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        head->next = temp;
        temp->prev = head;
        temp->next = nullptr;
        head = temp;
    }

    int get(int key) {
        auto el = m_cache.find(key);
        if (el == m_cache.end()) return -1;
        set_head(el->second);
        return el->second->val;
    }

    void put(int key, int value) {
        auto el = m_cache.find(key);
        if (el != m_cache.end()) {
            set_head(el->second);
            head->val = value;
        }
        else {
            if (m_capacity==2){
                m_cache.erase(tail->key);
                auto temp = new MyListNode(key, value, head);
                head = temp;
                tail = temp;
                tail->next = head;
                head->next = tail;
                m_cache[key] = head;
            }
            else {
                if (m_capacity==m_cache.size()+1){
                    m_cache.erase(tail->key);
                    tail = tail->next;
                    tail->prev = nullptr;
                }
                auto temp = new MyListNode(key, value, head);
                head->next = temp;
                head = temp;
                m_cache[key] = head;
            }
        }


    }
private:
    int m_capacity;
    std::unordered_map<int, MyListNode*> m_cache;
    MyListNode* head = nullptr;
    MyListNode* tail = nullptr;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main(){
    std::string ins[] =  {"LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"};
    int nums[][2] = {{2},{1,1},{2,2},{1},{3,3},{2},{4,4},{1},{3},{4}};
//    std::string ins[] =  {"LRUCache","put","put","put","put","get","get"};
//    int nums[][2] = {{2},{2,1},{1,1},{2,3},{4,1},{1},{2}};
//    std::string ins[] =  {"LRUCache","put","get","put","get","get"};
//    int nums[][2] = {{1},{2,1},{2},{3,2},{2},{3}};

//    std::vector<std::string> ins = readFileToStringVector("/Users/robertrochlin/Documents/Leetcode/146_LRUCache/input.txt");
//    std::vector< std::vector<int> > nums = readFileToInt2DVector("/Users/robertrochlin/Documents/Leetcode/146_LRUCache/input2.txt");
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
            std::cout<<param_1<<" ";
        }
        else if (i == "put"){
            obj->put(nums[j][0], nums[j][1]);
            std::cout<<"null ";
        }
        j++;
    }
    delete obj;
};