#include <string>
#include <vector>

using namespace std;

struct Node {
    Node *links[26];

    bool has_key(char c) { return links[c - 'a'] != nullptr; }

    Node *get_key(char c) { return links[c - 'a']; }

    void add_key(char c) { links[c - 'a'] = new Node(); }

    bool word = false;
};

void add_word(string s, Node *root) {
    auto temp = root;
    for (char c: s) {
        if (!temp->has_key(c))
            temp->add_key(c);
        temp = temp->get_key(c);
    }
    temp->word = true;
};

bool helper(string &s, int idx, Node *root, int n, vector<bool> &cache) {
    if (idx == n) return true;
    if (!cache[idx]) return false;
    auto temp = root;
    if (!temp->has_key(s[idx])) {
        cache[idx] = false;
        return false;
    }
    while (idx != n && temp->has_key(s[idx])) {
        if (temp->word && helper(s, idx, root, n, cache)) return true;
        temp = temp->get_key(s[idx++]);
    }
    if (temp->word && helper(s, idx, root, n, cache)) return true;
    cache[idx] = false;
    return false;
}

class Solution {
public:
    bool wordBreak(string s, vector<string> &wordDict) {
        auto root = new Node();
        for (string s: wordDict) {
            add_word(s, root);
        }
        vector<bool> cache(s.size(), true);
        return helper(s, 0, root, s.size(), cache);
    }

    bool wordBreakBetter(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1, false);
        dp[s.size()] = true;

        for (int i = s.size() - 1; i >= 0; i--) {
            for (const auto& w : wordDict) {
                if ((i + w.size()) <= s.size() && s.substr(i, w.size()) == w) {
                    dp[i] = dp[i + w.size()];
                }
                if (dp[i]) {
                    break;
                }
            }
        }

        return dp[0];
    }
};
