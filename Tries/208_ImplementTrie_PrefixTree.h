#ifndef LEETCODE_208_IMPLEMENTTRIE_PREFIXTREE_H
#define LEETCODE_208_IMPLEMENTTRIE_PREFIXTREE_H
#include <string>
#include <unordered_map>
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

class Trie {
private:
    Node* root; //starting trie with root

public:
    Trie() {
        root=new Node();   //for every reference variable we have, we need a new node for each one, with flag=false initially
    }

    //TC for insert, search and startsWith : O(n)
    //where n is length of word

    void insert(string word) {
        Node* node=root; //dummy node pointing to root
        for(int i=0; i<word.length(); i++){
            //chars in word exist in trie or not? => function - bool containsKey
            if(!node->containKey(word[i])){
                //doesnt contain the key
                node->put(word[i], new Node()); //at current node
            }
            //moves to reference trie
            node=node->get(word[i]);
        }
        node->setEnd();
    }

    bool search(string word) {
        Node* node=root;
        for(int i=0; i<word.length(); i++){
            if(!node->containKey(word[i])){
                return false;
            }
            node=node->get(word[i]);
        }
        return node->isEnd();
    }

    bool startsWith(string prefix) {
        Node* node=root;
        for(int i=0; i<prefix.length(); i++){
            if(!node->containKey(prefix[i])){
                return false;
            }
            node=node->get(prefix[i]);
        }
        return true;
    }
};

#endif //LEETCODE_208_IMPLEMENTTRIE_PREFIXTREE_H
