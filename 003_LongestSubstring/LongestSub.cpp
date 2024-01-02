
//https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
#include <iostream>
#include <unordered_set>
#include <string>
class Solution {
public:
    int lengthOfLongestSubstring(std::string s)
    {
      int l=0, r=0, max=0;
      std::unordered_set<char> set = std::unordered_set<char>();
      while (r < s.size()) {
        while(!set.insert(s[r]).second) set.erase(s[l++]);
        max = std::max(++r-l, max);
      }
      return max;
    }

    int lengthOfLongestSubstring2(std::string s) {
      /* interesting solution. Create a vector spanning the char set
        and then tracks the position of each of the last seen chars.
        it then sets start to the position of the previous duplicate
        which calculates the length as right after the repeat, effectively
        dumping the uneeded characters in a much more efficient manner than
        erasing them 1 at a time while checking if you can add them back.
      */
      std::vector<int> dict(256, -1);
      int maxLen = 0, start = -1;
      for (int i = 0; i != s.length(); i++) {
          if (dict[s[i]] > start)
              start = dict[s[i]];
          dict[s[i]] = i;
          maxLen = std::max(maxLen, i - start);
      }
      return maxLen;

    }
};
int main(){
  Solution sol;
  std::string s = "abcabcbb";
  std::cout<<sol.lengthOfLongestSubstring(s)<<"\n";
}; 
