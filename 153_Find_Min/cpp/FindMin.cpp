//https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

class Solution {
public:
  int findMin(std::vector<int>& nums) {
    if (*nums.begin() <= *nums.rbegin()) return *nums.begin();
    int l = 0,r=nums.size(),k;
    while(l+1<r){
      k = (l+r)/2;
      if (nums[k] > *nums.begin()) l = k;
      else r = k;
    }
    return std::min(nums[l],nums[r]);
  }
};

int main(){
    Solution sol;
    std::vector<int> vec({3,4,5,1,2});
    std::cout<<sol.findMin(vec)<<'\n';
} 
