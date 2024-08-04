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

struct
{
    bool operator()(ListNode* a, ListNode* b) const
    {
        if (b==nullptr) return true;
        if (a==nullptr) return false;
        return a->val < b->val;
    }
}ListNodeComp;

template <typename t> void move(std::vector<t>& v, size_t oldIndex, size_t newIndex)
{
    if (oldIndex > newIndex)
        std::rotate(v.rend() - oldIndex - 1, v.rend() - oldIndex, v.rend() - newIndex);
    else
        std::rotate(v.begin() + oldIndex, v.begin() + oldIndex + 1, v.begin() + newIndex + 1);
}

int find_insert(std::vector<ListNode*>& A, int T, size_t n){
    int L = 0;
    int R = n;
    while(L < R) {
        int m = ((L + R) / 2);
        if (A[m]->val < T) L = m + 1;
        else R = m;
    }
    if (n==L) return L-1;
    if (A[L]->val>T) return L-1; // return an index instead of rank
    return L;
}


class Solution {
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        std::sort(lists.begin(), lists.end(), ListNodeComp);
        while (!lists.empty() && lists.back()==nullptr) lists.erase(lists.end()-1);
        ListNode* head = new ListNode();
        ListNode* temp = head;
        size_t size = lists.size();
        while(!lists.empty()) {
            temp->next = lists[0];
            temp = lists[0];
            if (lists[0]->next == nullptr) { lists.erase(lists.begin()); size--; }
            else {
                int index = find_insert(lists, lists[0]->next->val, size);
                lists[0] = lists[0]->next;
                move(lists, 0, index);
            }
        }
        return head->next;
    }
};
int main(){
    Solution sol;
    int one[] = {};
    int two[] = {1};
    int three[] = {2,6};
    std::vector<ListNode*> vec;
    vec.push_back(nullptr);
    vec.push_back(make_linked_list(two));
//    vec.push_back(make_linked_list(three));
    auto sorted =  sol.mergeKLists(vec);
    while(sorted != nullptr) {
        std::cout<<sorted->val<<" ";
        sorted = sorted->next;
    }
};