#include <algorithm>

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
    for (int i : nodes1) {
        current = new ListNode(i);
        current->next = prev;
        prev = current;
    }
    return current;
}

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
    }
};



int main(){
    Solution sol;
    int nodes1[3] = {1,2,4};
    int nodes2[3] = {1,3,4};
    ListNode* head1 = make_linked_list(nodes1);
    



}; 