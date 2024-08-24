//
// Created by Robert Rochlin on 8/21/24.
//

#ifndef LEETCODE_152_MAXIMUMPRODUCTSUBARRAY_H
#define LEETCODE_152_MAXIMUMPRODUCTSUBARRAY_H
#include <vector>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        int curMin = 1, curMax = 1;

        for(int i = 0; i < nums.size(); i++)
        {
            int n = nums[i];

            int tmp = curMax * n;
            curMax = max(max(n * curMax, n * curMin), n);
            curMin = min(min(tmp, n * curMin), n);
            res = max(res, curMax);
        }

        return res;
    }
};


#endif //LEETCODE_152_MAXIMUMPRODUCTSUBARRAY_H
