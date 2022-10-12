#include "gtest/gtest.h"
#include "proj0.hpp"
#include <unordered_map>
#include <string>

// NOTE:  these are not intended as exhaustive tests.
// This should get you started testing.


namespace{

TEST(VerifySolution, First){
    std::string s1 = "POT";
    std::string s2 = "PAN";
    std::string s3 = "BIB";

    std::unordered_map<char, unsigned> solution = { {'A', 7}, {'B', 5}, 
        {'I', 0}, {'N', 4}, {'O', 3}, {'P', 2}, {'T', 1}
    };

    EXPECT_TRUE( verifySolution( s1, s2, s3, solution ) );
}

TEST(VerifySolution, Second){

    std::string s1 = "CAT";
    std::string s2 = "DOG";
    std::string s3 = "PIG";

    std::unordered_map<char, unsigned> solution = { {'A', 5}, {'C', 2}, {'D', 1}, {'G', 6}, {'I', 9}, {'O', 4}, {'P', 3}, {'T', 0} };

    EXPECT_TRUE( verifySolution( s1, s2, s3, solution ) );
} // end test two

TEST(VerifySolution, emptyString){

    std::string s1 = "";
    std::string s2 = "";
    std::string s3 = "";

    std::unordered_map<char, unsigned> solution = { {'A', 5}, {'C', 2}, {'D', 1}, {'G', 6}, {'I', 9}, {'O', 4}, {'P', 3}, {'T', 0} };

    EXPECT_TRUE( verifySolution( s1, s2, s3, solution ) );
} 
TEST(VerifySolution, emptyString_Alt){

    std::string s1 = "";
    std::string s2 = "";
    std::string s3 = "A";

    std::unordered_map<char, unsigned> solution = { {'A', 5}, {'C', 2}, {'D', 1}, {'G', 6}, {'I', 9}, {'O', 4}, {'P', 3}, {'T', 0} };

    EXPECT_FALSE( verifySolution( s1, s2, s3, solution ) );
} 

TEST(VerifySolution, longAndSameNumberPlus){

    std::string s1 = "AAAAAAAAAAAAA";
    std::string s2 = "OOOOOOOOOOOOO";
    std::string s3 = "IIIIIIIIIIIII";

    std::unordered_map<char, unsigned> solution = { {'A', 5}, {'C', 2}, {'D', 1}, {'G', 6}, {'I', 9}, {'O', 4}, {'P', 3}, {'T', 0} };

    EXPECT_TRUE( verifySolution( s1, s2, s3, solution ) );
} 
TEST(VerifySolution, longAndSameNumberPlus_Alt2){

    std::string s1 = "AAAAAAAAAAAAA";
    std::string s2 = "OOOOOOOOOOOOO";
    std::string s3 = "IIIIIIIIIIIIDD";

    std::unordered_map<char, unsigned> solution = { {'A', 5}, {'C', 2}, {'D', 1}, {'G', 6}, {'I', 9}, {'O', 4}, {'P', 3}, {'T', 0} };

    EXPECT_FALSE( verifySolution( s1, s2, s3, solution ) );
} 

TEST(VerifySolution, s1s2HasDifferentLength_shortVer){

    std::string s1 = "ACDGP";
    std::string s2 = "IGDCAT";
    // s1 + s2 = 1013413
    // 1013413 = DTDPODP
    std::string s3 = "DTDPODP";

    std::unordered_map<char, unsigned> solution = { {'A', 5}, {'C', 2}, {'D', 1}, {'G', 6}, {'I', 9}, {'O', 4}, {'P', 3}, {'T', 0} };

    EXPECT_TRUE( verifySolution( s1, s2, s3, solution ) );
} 

TEST(VerifySolution, doesnotEqual){

    std::string s1 = "ACDGPAA";
    std::string s2 = "IGDCATAD";
    // s1 + s2 = 1013413
    // 1013413 = DTDPODP
    std::string s3 = "DTDPODP";

    std::unordered_map<char, unsigned> solution = { {'A', 5}, {'C', 2}, {'D', 1}, {'G', 6}, {'I', 9}, {'O', 4}, {'P', 3}, {'T', 0} };

    EXPECT_FALSE( verifySolution( s1, s2, s3, solution ) );
} 

TEST(VerifySolution, s1s2HasDifferentLength_longerVer){

    std::string s1 = "AC"; // 52
    std::string s2 = "IIOPTACDIIOG"; // 994305219946
    // s1 + s2 = 994305219998
    // 994305219998 = DTDPODP
    std::string s3 = "IIOPTACDIIIK";

    std::unordered_map<char, unsigned> solution = { {'A', 5}, {'C', 2}, {'D', 1}, {'G', 6}, {'I', 9}, {'O', 4}, {'P', 3}, {'T', 0}, {'K',8} };

    EXPECT_TRUE( verifySolution( s1, s2, s3, solution ) );
} 
TEST(VerifySolution, s1s2HasDifferentLength_hasZeroVer){

    std::string s1 = "";
    std::string s2 = "IIOPTACDIIOG";
    // s1 + s2 = 994305219946
    // 994305219946 = IIOPTACDIIOG
    std::string s3 = "IIOPTACDIIOG";

    std::unordered_map<char, unsigned> solution = { {'A', 5}, {'C', 2}, {'D', 1}, {'G', 6}, {'I', 9}, {'O', 4}, {'P', 3}, {'T', 0} };

    EXPECT_TRUE( verifySolution( s1, s2, s3, solution ) );
} 


} // end namespace
