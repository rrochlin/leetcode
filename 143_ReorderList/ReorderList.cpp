#include <iostream>
#include <algorithm>
#include <vector>
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
    void reorderList(ListNode* head) {
        ListNode* copy = head;
        std::vector<ListNode*> tail;
        int len = 0;
        while (copy!=nullptr){
            tail.push_back(copy);
            copy = copy->next;
            len++;
        }
        len/=2;
        ListNode* next;
        auto it = tail.rbegin();
        while (len>0){
            next = head->next;
            head->next = *it;
            head->next->next = next;
            head = next;
            it++;
            len--;
        }
        head->next = nullptr;

    }
};


int main(){
    Solution sol;
    int nodes[4] = {1,2,3, 4};
    ListNode* head = make_linked_list(nodes);
    sol.reorderList(head);
    while(head != nullptr) {
        std::cout<<head->val<<" ";
        head = head->next;
    }
};