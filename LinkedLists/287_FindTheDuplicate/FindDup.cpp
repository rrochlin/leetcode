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
    int findDuplicate(std::vector<int>& nums) {
        int slow = 0, fast = 0;
        while(true){
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow==fast) break;
        }
        int slow2 = 0;
        while(true){
            slow2 = nums[slow2];
            slow = nums[slow];
            if (slow2 == slow) return slow;
        }
    }
};
int main(){
    Solution sol;
    std::vector<int> vec = {1,3,4,2,2};
    std::cout<<sol.findDuplicate(vec);
};