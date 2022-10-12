#include <unordered_map>
#include <string>
#include <cmath>
#include "proj0.hpp"

namespace {
    std::size_t stringToNumber(std::string s, const std::unordered_map<char, unsigned> & mapping) {
        std::size_t length_of_string = s.size();
        std::size_t sum_of_results = 0;
        for (unsigned i = 0; i < length_of_string; i++ ) {
             // for ABB, {A=1, B=2}, ABABB = 12122, A is at index 0, the length of string is 5, thus 1 * 10^4 = 1* 10(5 - 0 - 1)
             //  and for second B, B is at index 3, thus 2 * 10^1 = 2 * 10^(5-3-1)
            unsigned int current_place_of_10 = length_of_string - i - 1;
            // retrieve the digit value by key ---- the i th string
            unsigned int current_digit = mapping.at(s[i]);
            
            sum_of_results += current_digit * std::pow(10, current_place_of_10);
        }
        return sum_of_results;
    }
}

bool verifySolution(std::string s1, std::string s2, std::string s3, const std::unordered_map<char, unsigned> & mapping)
{
    std::size_t v1 = stringToNumber(s1, mapping);
    std::size_t v2 = stringToNumber(s2, mapping);
    std::size_t v3 = stringToNumber(s3, mapping);
    if (v1 + v2 == v3) {
        return true;
    } else {
        return false; // FYI, this stub is not a correct solution.
    }
}





