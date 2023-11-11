//https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

class Solution {
public:
    int findMin(std::vector<int>& nums) {
      return *std::min_element(nums.begin(), nums.end());
    }
};

int main(){
    Solution sol;
    std::vector<int> piles({3,6,7,11});
    std::cout<<sol.findMin(piles)<<'\n';
}
