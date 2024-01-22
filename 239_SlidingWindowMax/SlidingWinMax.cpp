#include <vector>
#include <iostream>

class Solution {
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
        int max=INT_MIN, l=0, r=k;
        std::vector<int> msw;
        for (int i=0;i<k;i++){
            max=std::max(max,nums[i]);
        }
        msw.push_back(max);
        while (r<nums.size()){
            if(nums[l]==max){
                max=INT_MIN;
                for (int i=l;i<l+k;i++){
                    max=std::max(max,nums[i+1]);
                }
            }
            max=std::max(max, nums[r]);
            l++, r++;
            msw.push_back(max);
        }
        return msw;
    }
};


int main(){
    Solution sol;
    std::vector<int> nums = {1,-1};
    int k = 1;
    for(int i:sol.maxSlidingWindow(nums, k)) std::cout<<i;
    std::cout<<std::endl;
}; 