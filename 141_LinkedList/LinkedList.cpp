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
    bool hasCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow = slow->next;
            fast = fast->next->next;
            if (fast==slow) return true;
        }
        return false;
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