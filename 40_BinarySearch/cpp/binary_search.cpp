#include <vector>
class Solution {
public:
    int search2(std::vector<int>& nums, int target) {

        int hi = nums.size() -1;
        int lo = 0;
        int i = 0;
        while (lo<=hi)
        {
            i = (hi+lo)/2;
            if(nums[i]==target) return i;
            else if(nums[i]<target) lo = i+1;
            else hi = i-1;
        }
        return -1;
    }
};