#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    int characterReplacement(std::string s, int k) {
        std::vector<int> numchars(26,0); // only need upper case english
        int  l=0, r=0;
        char mcc=s[0];
        while (r<s.length()){
            numchars[s[r]-'A']++;
            // potentially losing time here with frequent max char swapping
            if (numchars[mcc-'A'] < numchars[s[r]-'A']) mcc = s[r];
            if (r-l+1-numchars[mcc-'A'] > k) numchars[s[l++]-'A']--;
            r++;
        }
        return r-l;
        }
};

int main(){
  Solution sol;
//   std::string s = "ABAB";
//   std::cout<<sol.characterReplacement(s, 2)<<"\n";
  std::string s2 = "AABABBA";
  std::cout<<sol.characterReplacement(s2, 1)<<"\n";
}; 