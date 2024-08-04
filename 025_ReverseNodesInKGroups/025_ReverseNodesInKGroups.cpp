#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

template< typename T, size_t N>
ListNode* make_linked_list(T (&head)[N]){
    std::reverse(std::begin(head), std::end(head));
    ListNode* current;
    ListNode* prev = nullptr;
    ListNode* next = nullptr;
    for (int i : head) {
        current = new ListNode(i);
        current->next = prev;
        prev = current;
    }
    return current;
}

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head->next==nullptr) return head;
        int i;
        auto prev_head = new ListNode();
        ListNode* start;
        ListNode* current_head;
        bool first = true;
        ListNode* current = head;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        while(true){
            current_head = current;
            for (i=0;i<k;i++){
                next = current->next;
                current->next = prev;
                prev = current;
                current = next;
                if (current==nullptr) break;
            }
            if (first) {start=prev; first=false;}
            if (current==nullptr) break;
            prev_head->next = prev;
            prev_head = current_head;
            prev = nullptr;
            next = nullptr;
        }
        if (i<k-1){
            prev_head->next = current_head;
            current = prev;
            prev = nullptr;
            next = nullptr;
            while(current!=nullptr){
                next = current->next;
                current->next = prev;
                prev = current;
                current = next;
            }
        }
        else{
            prev_head->next = prev;
            prev_head = current_head;
        }
        return start;
    }
};
int main(){
    Solution sol;
    int one[] = {1,2,};
    auto vec = make_linked_list(one);
    auto sorted =  sol.reverseKGroup(vec,2);
    while(sorted != nullptr) {
        std::cout<<sorted->val<<" ";
        sorted = sorted->next;
    }
};