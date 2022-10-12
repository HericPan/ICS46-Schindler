#include "proj1.hpp"
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>


// // must be deleted!!
// #include <iostream>

// const bool DEBUG_OUT = false;


bool puzzleSolver(std::string s1, std::string s2, std::string s3, std::unordered_map<char, unsigned> & mapping)
{
	std::vector<bool> digitUseState(10, false); // index num is the digit num: index 0 is false means 0 is not used, index 9 is true menas 9 is used.

	// now reverse the three digit for better calculation
	std::reverse(s1.begin(), s1.end());
	std::reverse(s2.begin(), s2.end());
	std::reverse(s3.begin(), s3.end());

	// call search function here, and get the result of whether true or false
	// bool result = 
	bool result = search(1, 0, s1, s2, s3, 0, digitUseState, mapping);

	return result; // This is not the correct general solution. 
}

bool search(unsigned calculationOffset, unsigned currentPlace, std::string s1, std::string s2, std::string s3, unsigned carryIn, std::vector<bool>& digitUseState, std::unordered_map<char, unsigned> & mapping){
    if (currentPlace >= (s1.length()) && currentPlace >= (s2.length()) && currentPlace >= (s3.length())) {
		// base case 
		// we have successfully reach the end of the calculation
        // but if we find that 
        if (carryIn > 0) {
            return false;
        }
		return true;
	} 

    // looking for the first char
    if (calculationOffset % 3 == 1) {
        
        // if the first char does not exists 
        if (currentPlace >= s1.length()) {
            // we say that first Num does not exists 
            return search(calculationOffset+1, currentPlace, s1, s2, s3, carryIn, digitUseState, mapping);
        }

        char firstChar = s1.at(currentPlace);
        // if the first char already in the mapping
        if (mapping.count(firstChar) > 0) {
            return search(calculationOffset+1, currentPlace, s1, s2, s3, carryIn, digitUseState, mapping);
        }

        // now the first char need to search for its num
        for (unsigned i = 0; i <= 9; i++) {
            if (digitUseState.at(i) == false) {

                unsigned firstNum = i;

                // add the the result of second num to the mapping and the vector
                modifyOccupation(digitUseState, mapping, firstChar, firstNum, 1);

                bool result = search(calculationOffset+1, currentPlace, s1, s2, s3, carryIn, digitUseState, mapping);

                if (result == false) {
                    modifyOccupation(digitUseState, mapping, firstChar, firstNum, 0);
                } else {
                    return true;
                }
            }

        }
        // all tries from the for loop failed, return false
        return false;

    } else if (calculationOffset % 3 == 2) { // for second character
        
        // if the second char does not exists 
        if (currentPlace >= s2.length()) {
            // we say that first Num does not exists 
            return search(calculationOffset+1, currentPlace, s1, s2, s3, carryIn, digitUseState, mapping);
        }

        char secondChar = s2.at(currentPlace);
        // if the second char already in the mapping
        if (mapping.count(secondChar) > 0) {
            return search(calculationOffset+1, currentPlace, s1, s2, s3, carryIn, digitUseState, mapping);
        }

        // now the second char need to search for its num
        for (unsigned i = 0; i <= 9; i++) {
            if (digitUseState.at(i) == false) {

                unsigned secondNum = i;    
                

                // add the the result of second num to the mapping and the vector
                modifyOccupation(digitUseState, mapping, secondChar, secondNum, 1);

                bool result = search(calculationOffset+1, currentPlace, s1, s2, s3, carryIn, digitUseState, mapping);

                if (result == false) {
                    modifyOccupation(digitUseState, mapping, secondChar, secondNum, 0);
                } else {
                    return true;
                }
            }

        }
        // all tries from the for loop failed, return false
        return false;
        
    } else if (calculationOffset % 3 == 0) {
        // check whether the third number exists
        if (currentPlace >= s3.length()) {
            // if not exists, means that the s1 or s2 must longer than s3, and 1st + 2nd number should = 0
            unsigned firstNum = 0;
            unsigned secondNum = 0;
            // if the first and second num exists, get their number from mapping, else they are deemed as 0
            if (currentPlace < s1.length())
                firstNum = mapping.at(s1.at(currentPlace));
            if (currentPlace < s2.length())
                secondNum = mapping.at(s2.at(currentPlace));

            
            unsigned totalResultNum = carryIn + firstNum + secondNum;
            // unsigned resultDigit = totalResultNum % 10;
            unsigned carryOut = totalResultNum / 10;

            if (totalResultNum != 0) {
                return false;
            } else {
                // if equals, we should go to the last "currentPlace", which is the base case
                return search(calculationOffset+1, currentPlace+1, s1, s2, s3, carryOut, digitUseState, mapping);
            }

            
        } else if (currentPlace < s3.length() && currentPlace >= s1.length() && currentPlace >= s2.length()) {
            // this one is tricky, we don't have remaining digit from s1 and s2, the only one should get is carry in digit (1);
            unsigned thridNum = carryIn; // carry should be either 1 or 0
            char thirdChar = s3.at(currentPlace);
            
            if (mapping.count(thirdChar) > 0) {
                if (mapping.at(thirdChar) == thridNum) {
                    return search(calculationOffset+1, currentPlace+1, s1, s2, s3, 0, digitUseState, mapping);
                } else {
                    return false; // the result did not match our num already exists in mapping
                }
            }
            

            if (digitUseState.at(thridNum) == false) {
                modifyOccupation(digitUseState, mapping, thirdChar, thridNum, 1); 
                return search(calculationOffset+1, currentPlace+1, s1, s2, s3, 0, digitUseState, mapping); // this should lead to the base case, since this is the last digit
            } else {
                return false; // since 1 or 0 has been used, we have no choice for this number
            }

        } else {
            // third char exists, and either or both first char and second char exists
            char thirdChar = s3.at(currentPlace);
            unsigned firstNum = 0;
            unsigned secondNum = 0;
            if (currentPlace < s1.length())
                firstNum = mapping.at(s1.at(currentPlace));
            if (currentPlace < s2.length())
                secondNum = mapping.at(s2.at(currentPlace));

            unsigned totalResultNum = carryIn + firstNum + secondNum;
            
            unsigned resultDigit = totalResultNum % 10;
            unsigned carryOut = totalResultNum / 10;
            
            // if the thirdChar already have num mapping
            if (mapping.count(thirdChar) > 0) {
                if (mapping.at(thirdChar) == resultDigit) {
                    return search(calculationOffset+1, currentPlace+1, s1, s2, s3, carryOut, digitUseState, mapping);
                } else {
                    return false; // the result did not match our num already exists in mapping
                }
            } else {
                // we now need to add the third into the mapping
                if (digitUseState.at(resultDigit) == false) {
                    modifyOccupation(digitUseState, mapping, thirdChar, resultDigit, 1);
                    bool result = search(calculationOffset+1, currentPlace+1, s1, s2, s3, carryOut, digitUseState, mapping);

                    if (result == false) {
                        modifyOccupation(digitUseState, mapping, thirdChar, resultDigit, 0);
                    } else {
                        return true;
                    }
                } else {
                    return false; // since this digit has been occupied
                }
            }


        }

    }

    // should return false if no matching, but the return here should be invalid.
    return false;

}

void modifyOccupation(std::vector<bool>& digitUseState, std::unordered_map<char, unsigned> & mapping, char character, unsigned digitForCharacter, unsigned mode){
	
	// check the mode, if mode = 1, add mapping and set digital use state, else is backtracing, delete and erase the number and character from vector and mapping
	if (mode == 1) {
		
		mapping.emplace(character, digitForCharacter);
		digitUseState.at(digitForCharacter) = true;

	} else {
		
		mapping.erase(character);
		digitUseState.at(digitForCharacter) = false;

	}

}

