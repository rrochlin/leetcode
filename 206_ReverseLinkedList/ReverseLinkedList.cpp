#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return head;
        ListNode* tail;
        ListNode* prev_node = nullptr;
        while (head->next != nullptr) {
            if (prev_node == nullptr) tail = new ListNode(head->val);
            else tail = new ListNode(head->val, prev_node);
            prev_node = tail;
            head = head->next;
        }
        tail = new ListNode(head->val, prev_node);
        return tail;
    }
    ListNode* reverseListFAST(ListNode* head) {
        ListNode* current = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;

        if(head == NULL) {
            return NULL;
        }

        while(current != NULL) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev;
        return head;
    }
};

int main(){
    Solution sol;
    int nodes[5] = {5,4,3,2,1};
    ListNode* node;
    ListNode* prev_node = nullptr;
    for (int i : nodes){
        if (prev_node==nullptr) node = new ListNode(i);
        else node = new ListNode(i, prev_node);
        prev_node = node;
    }

    ListNode* reverse = sol.reverseList(node);
    while (reverse != nullptr) {
        std::cout<<reverse->val<<" ";
        reverse = reverse->next;
    }


}; 