#include <vector>
#include <cmath>
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

    int search(std::vector<int>& nums, int target) {
        int divisor = nums.size()/2;
        auto it = nums.begin() + divisor;
        if (divisor == 1) {
            if (*it > target) it -= divisor;
            else if (*it < target) it += divisor;
        }
        while(*it != target){
            if (divisor<=1) return -1;
            divisor = std::ceil(divisor / 2.0);
            if (*it > target) it -= divisor;
            else if (*it < target) it += divisor;
        }
        return it-nums.begin();
    }
};