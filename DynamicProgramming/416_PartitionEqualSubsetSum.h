//
// Created by Robert Rochlin on 8/25/24.
//

#ifndef LEETCODE_416_PARTITIONEQUALSUBSETSUM_H
#define LEETCODE_416_PARTITIONEQUALSUBSETSUM_H
#include <vector>
#include <unordered_map>
using namespace std;

bool dfs(vector<int>& nums, int target, int idx, int n, vector<vector<bool>>& m){
    if(target<=0 || idx>=n) return target==0;
    if(!m[idx][target]) return false;
    for(int i=idx; i<n; i++){
        if(dfs(nums, target-nums[i], i+1, n, m)) return true;
    }
    m[idx][target] = false;
    return false;
}

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i:nums) sum+=i;
        if(sum&1) return false;
        sum=sum>>1;
        vector<vector<bool>> m(nums.size(), vector<bool>(sum+1,true));
        return dfs(nums, sum, 0, nums.size(), m);
    }
};

#endif //LEETCODE_416_PARTITIONEQUALSUBSETSUM_H
