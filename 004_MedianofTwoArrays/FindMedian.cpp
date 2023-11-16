//https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
      return 0;        
    }
};

int main(){
    Solution sol;
    std::vector<int> vec({1,3});
    std::vector<int> vec2({2});
    std::cout<<sol.findMedianSortedArrays(vec, vec2)<<'\n';
}; 
