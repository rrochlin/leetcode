// https://leetcode.com/problems/merge-two-sorted-lists/description/
#include <iostream>
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
    for (int i : head) {
        current = new ListNode(i);
        current->next = prev;
        prev = current;
    }
    return current;
}

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1==nullptr) return list2;
        if (list2==nullptr) return list1;
        ListNode* head;
        if (list1->val > list2->val){
            head = new ListNode(list2->val);
            list2 = list2->next;
        } else {
            head = new ListNode(list1->val);
            list1 = list1->next;
        }
        ListNode* current = head;
        ListNode* next;
        while(list1!=NULL || list2!=NULL){
            if (list1->val > list2->val){
                next = new ListNode(list2->val);
                list2 = list2->next;
            } else {
                next = new ListNode(list1->val);
                list1 = list1->next;
            }
            current->next = next;
            current = next;
        }
        if (list1==NULL) next = list2; 
        else next = list1; 
        current->next = next;
        return head; 
    }
};



int main(){
    Solution sol;
    int nodes1[3] = {1,2,4};
    int nodes2[3] = {1,3,4};
    ListNode* head1 = make_linked_list(nodes1);
    ListNode* head2 = make_linked_list(nodes2);
    ListNode* merged = sol.mergeTwoLists(head1, head2);
    while(merged != nullptr) {
        std::cout<<merged->val<<" ";
        merged = merged->next;
    }
}; 