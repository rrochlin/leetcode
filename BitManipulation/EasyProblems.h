//
// Created by Robert Rochlin on 8/26/24.
//

#ifndef LEETCODE_338_COUNTINGBITS_H
#define LEETCODE_338_COUNTINGBITS_H
#include <vector>
#include <bitset>
using namespace std;

class Solution {
public:

    int singleNumber(vector<int>& nums) {
        int res=nums[0];
        for(int i=1; i<nums.size(); i++){
            res ^= nums[i];
        }
        return res;
    }

    vector<int> countBits(int n) {
        vector<int> res(n+1,0);
        for (int i=1; i<n+1; i++){
            res[i] = res[i>>1] + (i&1);
        }
        return res;
    }
    // done with builtin libs
    uint32_t reverseBitsBuiltin(uint32_t n) {
        bitset<32> num {n};
        auto s = num.to_string();
        reverse(s.begin(), s.end());
        bitset<32> res{s};
        return (uint32_t) res.to_ulong();
    }
    // fill in n from both ways at once
    uint32_t reverseBits(uint32_t n) {
        for(int i=0;i<=15;i++){
            if(n&1<<i && !(n&1<<(31-i))){
                n=n^1<<i;
                n=n^1<<(31-i);
            }
            else if(!(n&1<<i) && n&1<<(31-i)){
                n=n^1<<i;
                n=n^1<<(31-i);
            }
        }
        return n;
    }
    // bit manip solution
    int missingNumber(vector<int>& nums) {
        int res=nums.size();
        for (int i=0; i<nums.size(); i++){
            res^=nums[i];
            res^=i;
        }
        return res;
    }
    // math based solution
    int missingNumber2(vector<int>& nums) {
        int n=nums.size();
        int sum=(n*(n+1)/2);
        int s2=0;
        for(int i=0;i<n;i++)
        {
            s2+=nums[i];
        }
        return sum-s2;
    }
};
#endif //LEETCODE_338_COUNTINGBITS_H
