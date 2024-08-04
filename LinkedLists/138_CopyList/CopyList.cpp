// https://leetcode.com/problems/copy-list-with-random-pointer/description/
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <map>
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return head;
        Node* new_head = new Node(head->val);
        Node* start = new_head;
        std::vector<Node*> randoms;
        std::unordered_map<Node*, int> order;
        int i = 0;
        std::vector<Node*> new_nodes;
        new_nodes.push_back(new_head);
        while(true) {
            randoms.push_back(head->random);
            order[head] = i++;
            head = head->next;
            if (head==nullptr) break;
            new_head->next = new Node(head->val);
            new_head = new_head -> next;
            new_nodes.push_back(new_head);
        }
        order[nullptr] = i;
        new_nodes.push_back(nullptr);
        new_head = start;
        for (Node* n : randoms) {
            new_head->random = new_nodes[order.at(n)];
            new_head = new_head->next;
        }
        return start;
    }

    Node* copyRandomList(Node* head) {
        if (head == nullptr) return head;
        Node* new_head = new Node(head->val);
        Node* start = new_head;
        std::vector<Node*> randoms;
        std::unordered_map<Node*, int> order;
        int i = 0;
        std::vector<Node*> new_nodes;
        new_nodes.push_back(new_head);
        while(true) {
            randoms.push_back(head->random);
            order[head] = i++;
            head = head->next;
            if (head==nullptr) break;
            new_head->next = new Node(head->val);
            new_head = new_head -> next;
            new_nodes.push_back(new_head);
        }
        order[nullptr] = i;
        new_nodes.push_back(nullptr);
        new_head = start;
        for (Node* n : randoms) {
            new_head->random = new_nodes[order.at(n)];
            new_head = new_head->next;
        }
        return start;
    }

    Node* copyRandomListLowMem(Node* head) {
        if(head == NULL){
            return NULL;
        }

        else{
            // First, we construct a new list. We modify the next pointer of each node in the
            // original list such that it points to the corresponding node in the new list.
            std::vector<Node*> vec;
            Node* newHead = NULL;
            Node* newTail = NULL;
            Node* tmp1 = head;
            Node* tmp2 = NULL;
            while(tmp1 != NULL){
                vec.push_back(tmp1);
                if(newTail == NULL){
                    newHead = new Node(tmp1->val);
                    newTail = newHead;
                }
                else{
                    newTail->next = new Node(tmp1->val);
                    newTail = newTail->next;
                }

                tmp2 = tmp1;
                tmp1 = tmp1->next;
                tmp2->next = newTail;
            }

            // Set the random pointer in the new list.
            tmp1 = newHead;
            for(int i=0; i<vec.size(); i++){
                if(vec[i]->random != NULL){
                    tmp1->random = vec[i]->random->next;
                }
                else{
                    tmp1->random = NULL;
                }

                tmp1 = tmp1->next;
            }

            // Recover the original list
            for(int i=0; i<vec.size()-1; i++){
                vec[i]->next = vec[i+1];
            }
            vec[vec.size()-1]->next = NULL;

            return newHead;
        }
    }
    Node* copyRandomListFast(Node* head) {
        // return head;
        Node* temp=head;
        std::unordered_map<Node*, Node*> mpp;
        while(temp!=NULL){
            Node* newnode=new Node(temp->val);
            mpp[temp]=newnode;
            temp=temp->next;
        }
        temp=head;
        while(temp!=NULL){
            Node* copynode=mpp[temp];
            copynode->next=mpp[temp->next];
            copynode->random=mpp[temp->random];
            temp=temp->next;
        }
        return mpp[head];

    }
};


int main(){
    Solution sol;
};