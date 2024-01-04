#include <iostream>
#include <string>
#include <vector>

class Solution {
    // inspired by the solution to 003 
public:
    int characterReplacement(std::string s, int k) {
        std::vector<int> numchars(91,0); // only need upper case english 65-90
        int badchars=0, l=0, r=0;
        char mcc=s[0];
        while (r<s.length()){
            numchars[s[r]]++;
            if (numchars[mcc] < numchars[s[r]]){
                badchars += numchars[mcc]-numchars[s[r]]+1;
                mcc = s[r];
            }
            else if (s[r] != mcc) badchars++;
            if (badchars > k){
                numchars[s[l]]--;
                if (s[l++]!=mcc) badchars--;
            }
            r++;
        }
        return r-l;
    }
};

int main(){
  Solution sol;
//   std::string s = "ABAB";
//   std::cout<<sol.characterReplacement(s, 2)<<"\n";
  std::string s2 = "ABCDE";
  std::cout<<sol.characterReplacement(s2, 1)<<"\n";
}; 