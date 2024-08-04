//https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

class Solution {
public:
  int search(std::vector<int>& nums, int target) {
    int pivot = findPivot(nums), l, r;
    if (pivot!=0 && *nums.begin() <= target) l = 0, r = pivot-1;
    else l = pivot, r = nums.size()-1;
    while(l<=r){
        int k = (l+r)/2;
        if (nums[k]==target) return k;
        else if (nums[k] < target) l = k+1;
        else r = k-1;
    }
    return -1;
  }

  int findPivot(std::vector<int>& nums){
    if (*nums.begin() <= *nums.rbegin()) return 0;
    int l = 0,r=nums.size(),k;
    while(l+1<r){
      k = (l+r)/2;
      if (nums[k] > *nums.begin()) l = k;
      else r = k;
    }
    return nums[l]>nums[r]?r:l;
  }
};

int main(){
    Solution sol;
    std::vector<int> vec({3,1});
    std::cout<<sol.search(vec,3)<<'\n';
} 
