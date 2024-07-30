#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class LRUCache {
public:
    LRUCache(int capacity) {
        m_capacity = capacity;
    }

    int get(int key) {
        auto el = m_cache.find(key);
        if (el == m_cache.end()) return -1;
        if(tail != nullptr && head != nullptr) {
            if (tail->val == key) {
                ListNode* temp = tail;
                head->next = tail;
                tail = tail->next;
                head = head->next;
                head->next = nullptr;

            } else if (head->val != key) {
                ListNode *prev;
                ListNode *temp = tail;
                while (temp->val != key) {
                    prev = temp;
                    temp = temp->next;
                }
                prev->next = temp->next;
                head->next = temp;
                head = temp;
                head->next = nullptr;
            }
        }
        return el->second;
    }

    void put(int key, int value) {
        auto el = m_cache.find(key);
        if (tail!=nullptr && head!=nullptr && el != m_cache.end()) {
            if (tail->val==key) {
                head->next = tail;
                tail = tail->next;
                head = head->next;
                head->next = nullptr;
            }
            else if (head->val!=key) {
                ListNode* prev;
                ListNode* temp = tail;
                while(temp->val != key) {
                    prev = temp;
                    temp = temp->next;
                }
                prev->next = temp->next;
                head->next = temp;
                head = temp;
                head->next = nullptr;
            }
        }
        else {
            if (tail==nullptr) tail = new ListNode(key);
            else if (head==nullptr) {
                head = new ListNode(key);
                tail->next = head;
            }
            else {
                head->next = new ListNode(key);
                head = head->next;
            }
        }
        if (el == m_cache.end()) {
            if (m_capacity > 0) m_capacity--;
            else {
                m_cache.erase(tail->val);
                tail = tail->next;
            }
        }
        m_cache[key] = value;


    }
private:
    int m_capacity;
    std::unordered_map<int, int> m_cache;
    ListNode* tail = nullptr;
    ListNode* head = nullptr;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main(){
//    std::string ins[] =  {"LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"};
//    int nums[][2] = {{2},{1,1},{2,2},{1},{3,3},{2},{4,4},{1},{3},{4}};
//    std::string ins[] =  {"LRUCache","put","put","put","put","get","get"};
//    int nums[][2] = {{2},{2,1},{1,1},{2,3},{4,1},{1},{2}};
    std::string ins[] =  {"LRUCache","put","put","put","put","get","get","get","get","put","get","get","get","get","get"};
    int nums[][2] = {{3},{1,1},{2,2},{3,3},{4,4},{4},{3},{2},{1},{5,5},{1},{2},{3},{4},{5}};
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