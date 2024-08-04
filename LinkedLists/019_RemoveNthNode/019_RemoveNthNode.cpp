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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* before = head;
        ListNode* fast = head->next;
        int sz = 1;
        while(fast && fast->next) {
            fast = fast->next->next;
            sz+=2;
        }
        if (fast != nullptr) sz++;
        if (sz==n) {
            head = head->next;
            return head;
        }
        for(int i=0; i < sz - n - 1; i++) before = before->next;
        if (before->next == nullptr) return head;
        before->next = before->next->next;
        return head;
    }

    ListNode* removeNthFromEndFast(ListNode* head, int n) {

        if(!head || !head->next){
            return nullptr;
        }

        int l = 0;
        ListNode *length = head;
        while(length){
            l++;
            length = length->next;
        }

        if(l == n) return head->next;

        ListNode *slow = head;
        ListNode *fast = head;

        //int index = 0;
        for(int i = 0; i < n; i++){
            fast = fast->next;
        }

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next;
        }

        slow->next = slow->next->next;

        return head;
    }
};


int main(){
    Solution sol;
    int nodes[5] = {1,2,3, 4, 5};
    int nodes2[2] = {1,2};
    ListNode* head = make_linked_list(nodes2);
    head = sol.removeNthFromEnd(head,2);
    while(head != nullptr) {
        std::cout<<head->val<<" ";
        head = head->next;
    }
};