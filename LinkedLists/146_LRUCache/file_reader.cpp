#include "file_reader.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>

// Function to trim whitespace from both ends of a string
std::string trim(const std::string& str) {
    size_t first = str.find_first_not_of(' ');
    if (first == std::string::npos) {
        return "";
    }
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, last - first + 1);
}

// Function to read file into a std::vector<std::string>
std::vector<std::string> readFileToStringVector(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<std::string> values;
    std::string line;

    if (file.is_open()) {
        if (std::getline(file, line)) {
            std::stringstream ss(line);
            std::string value;
            while (std::getline(ss, value, ',')) {
                // Remove brackets and quotes
                value = trim(value);
                if (value.front() == '[') value.erase(0, 1);
                if (value.back() == ']') value.pop_back();
                if (value.front() == '\"') value.erase(0, 1);
                if (value.back() == '\"') value.pop_back();
                values.push_back(value);
            }
        }
        file.close();
    } else {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }
    return values;
}

// Function to read file into a 2D vector of integers
std::vector<std::vector<int>> readFileToInt2DVector(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<std::vector<int>> intArray;
    std::string line;

    if (file.is_open()) {
        if (std::getline(file, line)) {
            std::stringstream ss(line);
            std::string number;
            std::vector<int> temp;
            for (char ch : line) {
                if (std::isdigit(ch) || ch == '-') {
                    number += ch;
                } else if (!number.empty()) {
                    temp.push_back(std::stoi(number));
                    number.clear();
                }
                if (ch == ']') {
                    if (!temp.empty()) {
                        intArray.push_back(temp);
                        temp.clear();
                    }
                }
            }
        }
        file.close();
    } else {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }
    return intArray;
}
