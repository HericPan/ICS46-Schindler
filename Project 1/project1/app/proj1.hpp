#ifndef __PROJ_1__HPP
#define __PROJ_1__HPP

#include <unordered_map>

/* 
 * Project 1:  you need to implement this function.
 I promise that any of my test cases will have an empty 
 	map as the fourth parameter when called.
 If the puzzle IS solvable, return true AND make the mapping indicate the solution.
 If the puzzle is NOT solvable, it is enough to return false.

 See the project 1 write-up for a better description. 
 */


bool puzzleSolver(std::string s1, std::string s2, std::string s3, std::unordered_map<char, unsigned> & mapping);


bool search(unsigned calculationOffset, unsigned currentPlace, std::string s1, std::string s2, std::string s3, unsigned carryIn, std::vector<bool>& digitalUseState, std::unordered_map<char, unsigned> & mapping);


// mode = 1 for adding, mode = 0 for backtracing
void modifyOccupation(std::vector<bool>& digitalUseState, std::unordered_map<char, unsigned> & mapping, char character, unsigned digitForCharacter, unsigned mode); 


#endif