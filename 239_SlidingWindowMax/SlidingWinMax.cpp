#include <vector>
#include <iostream>
#include <deque>

class Solution {
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
        int l=0, r=k;
        std::vector<int> msw;
        std::deque<int> dq;
        dq.push_back(nums[0]);
        for (int i=1;i<k;i++){
            while (!dq.empty() && nums[i] > dq.back()) dq.pop_back();
            dq.push_back(nums[i]);
        }
        msw.push_back(dq.front());
        while (r<nums.size()){
            if(nums[l]==dq.front()) dq.pop_front();
            while (!dq.empty() && nums[r] > dq.back()) dq.pop_back();
            dq.push_back(nums[r]);
            l++, r++;
            msw.push_back(dq.front());
        }
        return msw;
    }
};


int main(){
    Solution sol;
    std::vector<int> nums = {1,3,1,2,0,5};
    int k = 3;
    for(int i:sol.maxSlidingWindow(nums, k)) std::cout<<i;
    std::cout<<std::endl;
}; 