#include <iostream>
#include <unordered_map>
#include <cmath>
#include "proj0.hpp"

// Note:  you are not required to implement a main() for this project.
//      Feel free to create one; it will not be accounted for in grading.
//      Be sure to use the unit testing process to test your code: that is
//      how we will be grading. 

std::size_t stringToNumber(std::string s, const std::unordered_map<char, unsigned> & mapping) {
        std::size_t length_of_string = s.size();
        unsigned long sum_of_results = 0;
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

int main()
{
    unsigned long long i;
    i = stringToNumber("ABABB", std::unordered_map<char, unsigned>{{'A', 1}, {'B',2}}) ;
    std::cout << i << std::endl;
    i = stringToNumber("ACGIOPDTAAACAGT", std::unordered_map<char, unsigned>{ {'A', 5}, {'C', 2}, {'D', 1}, {'G', 6}, {'I', 9}, {'O', 4}, {'P', 3}, {'T', 0} }) ;
    std::cout << i << std::endl;
    return 0;
}



