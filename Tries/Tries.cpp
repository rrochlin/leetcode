#include "212_WordSearchII.h"

int main() {
//    std::vector<std::string> ops {"Trie","insert","search","search","startsWith","insert","search"};
//    std::vector<std::string> vals {"","apple","apple","app","app","app","app"};
//    Trie* obj;
//    for(int i = 0; i<ops.size(); i++){
//        if(ops[i]=="Trie") obj = new Trie();
//        else if(ops[i]=="insert") {
//            obj->insert(vals[i]);
//            std::cout << "insert; ";
//        }
//        else if(ops[i]=="search") std::cout<<(obj->search(vals[i]) ? "search true; " : "search false; ");
//        else if(ops[i]=="startsWith") std::cout<<(obj->startsWith(vals[i]) ? "starts with true; " : "starts with false; ");
//    }
    auto sol = new Solution();
    std::vector<std::vector<char>> board = {{'o','a','a','n'},{'e','t','a','e'},{'i','h','k','r'},{'i','f','l','v'}};
    std::vector<string> words = {"oath","pea","eat","rain"};
    sol->findWords(board, words);
}