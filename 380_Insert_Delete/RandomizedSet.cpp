#include <iostream>

#include <string>
#include <vector>
#include <unordered_set>

class RandomizedSet {
public:
    std::unordered_set<int> numbers;
    RandomizedSet() {
        std::srand(std::time(nullptr));
    }
    
    bool insert(int val) {
        return numbers.insert(val).second;
    }
    
    bool remove(int val) {
        return numbers.erase(val)==1;
    }
    
    int getRandom() {
        auto it = numbers.begin();
        std::advance(it, std::rand() % std::distance(it, numbers.end()));
        return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main() {
    RandomizedSet* obj;
    auto commands = {
        std::string("RandomizedSet"),
        std::string("insert"),
        std::string("remove"),
        std::string("insert"),
        std::string("getRandom"),
        std::string("remove"),
        std::string("insert"),
        std::string("getRandom")
    };
    std::vector<int> numbers = {{},{1},{2},{2},{},{1},{2},{}};

    for (auto it=commands.begin(); it!=commands.end(); ++it){
        switch (*it.at(0))
        {
        case 'R': 
            obj = new RandomizedSet();
            break;
        
        case 'i':
            if (obj->insert(numbers[(int) std::distance(commands.begin(), it)])) std::cout<<"true ";
            else std::cout<<"false ";
            break;

        case 'r':
            if (obj->remove(numbers[(int) std::distance(commands.begin(), it)])) std::cout<<"true ";
            else std::cout<<"false ";
            break;

        case 'g':
            std::cout<<obj->getRandom()<<" ";
            break;

        default:
            break;
        }
    }
    

    // bool param_1 = obj->insert(val);
    // bool param_2 = obj->remove(val);
    // int param_3 = obj->getRandom();
}