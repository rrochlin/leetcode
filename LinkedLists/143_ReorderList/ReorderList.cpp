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
    void reorderListFast(ListNode* head) {
            //ios_base::sync_with_stdio(false);
            //cin.tie(nullptr);
            ListNode* slow = head;
            ListNode* fast = head->next;
            while(fast && fast->next){
                slow = slow->next;
                fast = fast->next->next;
            }
            ListNode* second = slow->next;
            ListNode* prev = slow->next = nullptr;
            while(second!=nullptr){
                ListNode* temp = second->next;
                second->next = prev;
                prev = second;
                second = temp;
            }
            ListNode* first = head;
            second = prev;
            while(second!=nullptr){
                ListNode* temp1 = first->next;
                ListNode* temp2 = second->next;
                first->next = second;
                second->next = temp1;
                first = temp1;
                second = temp2;
            }
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