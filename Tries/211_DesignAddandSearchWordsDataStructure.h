//
// Created by Robert Rochlin on 8/13/24.
//

#ifndef LEETCODE_211_DESIGNADDANDSEARCHWORDSDATASTRUCTURE_H
#define LEETCODE_211_DESIGNADDANDSEARCHWORDSDATASTRUCTURE_H
#include <string>
#include <map>
#include <vector>
using namespace std;
struct Node {
    Node *links[26];
    bool flag = false;
    //checks if the reference trie is present or not
    bool containKey(char ch) {
        return (links[ch - 'a'] != NULL);
    }
    //creating reference trie
    void put(char ch, Node *node) {
        links[ch - 'a'] = node;
    }
    //to get the next node for traversal
    Node *get(char ch) {
        return links[ch - 'a'];
    }
    //setting flag to true at the end of the word
    void setEnd() {
        flag = true;
    }
    //checking if the word is completed or not
    bool isEnd() {
        return flag;
    }
};


class WordDictionary {
public:
    WordDictionary() {
        trie = new Node();
    }

    void addWord(std::string word) {
        Node* node = trie;
        for(char c : word){
            if(!node->containKey(c)) node->put(c, new Node());
            node = node->get(c);
        }
        node->setEnd();
    }

    bool search(std::string word) {
        vector<Node*> next {trie};
        for(char c : word){
            vector<Node*> temp = next;
            next.clear();
            if(c=='.'){
                for(auto n : temp){
                    for(int i = 'a'; i <='z'; i++){
                        if(n->containKey(i)) next.push_back(n->get(i));
                    }
                }
            } else {
                for(auto n : temp) {
                    if(n->containKey(c)) next.push_back(n->get(c));
                }
                if(next.empty()) return false;
            }
        }
        for(auto n : next) if(n->isEnd()) return true;
        return false;
    }
private:
    Node* trie;
};
#endif //LEETCODE_211_DESIGNADDANDSEARCHWORDSDATASTRUCTURE_H
