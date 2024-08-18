//
// Created by Robert Rochlin on 8/18/24.
//

#ifndef LEETCODE_133_CLONEGRAPH_H
#define LEETCODE_133_CLONEGRAPH_H

#include <vector>
#include <stack>
#include <set>
#include <unordered_map>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return {};
        auto root = new Node(node->val);
        unordered_map<Node*, Node*> m{{node,root}};
        stack<Node*> s{{node}};
        while(!s.empty()){
            auto t = s.top();
            s.pop();
            for(int i=0; i<t->neighbors.size(); i++){
                if(m.find(t->neighbors[i])==m.end()) {
                    m[t->neighbors[i]] = new Node(t->neighbors[i]->val);
                    s.push(t->neighbors[i]);
                }
                m[t]->neighbors.push_back(m[t->neighbors[i]]);
            }
        }
        return root;
    }
};

#endif //LEETCODE_133_CLONEGRAPH_H
