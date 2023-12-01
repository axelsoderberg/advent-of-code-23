#include <vector>
#include <iostream>
#include <fstream>
#include <sstream> 
#include <string>
#include <algorithm>
#include <iterator>

std::vector<int> readInput(std::string fileName);
int textDigit(std::string substr);

int main()
{
    std::ifstream file("input_day1.txt");
    std::stringstream is;
    std::string s;
    int val = 0;
    if (file) {
        is << file.rdbuf();
        file.close();
    }

    // The digits, we use -1 for first to update it only for the first
    int first = -1;
    int last;

    while (getline(is, s)) {
        std::cout << s << "\n";
        for (int i = 0; i < s.size(); i++) {
            char c = s.at(i);
            if (isdigit(c)) {
                if (first == -1)
                    first = c - 48;
                last = c - 48;
            }
            // We send i + 5 because that is the max lenght of the digits in text
            int d = textDigit(s.substr(i, i + 5));
            if (d != -1) {
                if (first == -1)
                    first = d;
                last = d;
            }
        }
        //std::cout << first * 10 + last << "\n";
        val += first * 10 + last;
        // Reset first
        first = -1;
    }
    std::cout << "Total: " << val;
}

int textDigit(std::string substr) {
    int digit = -1;
    if (substr.find("one") == 0)   return 1;
    if (substr.find("two") == 0)   return 2;
    if (substr.find("three") == 0) return 3;
    if (substr.find("four") == 0)  return 4;
    if (substr.find("five") == 0)  return 5;
    if (substr.find("six") == 0)   return 6;
    if (substr.find("seven") == 0) return 7;
    if (substr.find("eight") == 0) return 8;
    if (substr.find("nine") == 0)  return 9;
    if (substr.find("zero") == 0)  return 0;
    return digit;
}