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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        std::vector<int> nums;
        int carry = 0;
        while(l1!=nullptr && l2!=nullptr){
            int res = l1->val + l2->val + carry;
            nums.push_back(res%10);
            carry = res/10;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1!=nullptr){
            int res = l1->val + carry;
            nums.push_back(res%10);
            l1 = l1->next;
            carry=res/10;
        }
        while (l2!=nullptr){
            int res = l2->val + carry;
            nums.push_back(res%10);
            l2 = l2->next;
            carry=res/10;
        }
        if(carry==1) nums.push_back(1);
        ListNode* head;
        ListNode* tmp = nullptr;
        for(auto it=nums.rbegin();it!=nums.rend();it++){
            head = new ListNode(*it);
            head->next = tmp;
            tmp = head;
        }
        return head;
    }
};


int main(){
    Solution sol;
    int nodes[3] = {2,4,3};
    int nodes2[3] = {5,6,4};
    ListNode* head1 = make_linked_list(nodes);
    ListNode* head2 = make_linked_list(nodes2);
    ListNode* head = sol.addTwoNumbers(head1, head2);
    while(head != nullptr) {
        std::cout<<head->val<<" ";
        head = head->next;
    }
};