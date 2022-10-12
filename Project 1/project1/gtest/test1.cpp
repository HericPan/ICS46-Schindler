#include "gtest/gtest.h"
#include "proj1.hpp"
#include "ver.hpp" 
#include <unordered_map>
#include <string>


/*
 
Note that this IS NOT a comprehensive set of test cases.
You should still write additional test cases.

This is to get you started and serve as a sanity check.


Note that "gradeYesAnswer" is provided for use in your test cases, but 
you may NOT use it in any code you write otherwise for this project.

 */


namespace{

TEST(SimpleCases, PotPanBib){

    std::unordered_map<char, unsigned> puzzle;

    bool p1 = puzzleSolver("POT", "PAN", "BIB", puzzle);
    EXPECT_TRUE( p1 &&  gradeYesAnswer("POT", "PAN", "BIB", puzzle) ) ;
}

TEST(SimpleCases, NeatFind){

    std::unordered_map<char, unsigned> puzzle;

    bool p1 = puzzleSolver("UCI", "ALEX", "MIKE", puzzle);
    EXPECT_TRUE( p1 &&  gradeYesAnswer("UCI", "ALEX", "MIKE", puzzle) );
} // end test two, "NeatFind"


TEST(SimpleCases, FirstNo){

    std::unordered_map<char, unsigned> puzzle;

    bool p1 = puzzleSolver("LARRY", "CAREER", "LEGEND", puzzle);
    EXPECT_FALSE( p1 );
}

TEST(SimpleCases, FirstNo2){

    std::unordered_map<char, unsigned> puzzle;

    bool p1 = puzzleSolver("GABA", "GBAB", "CDCCC", puzzle);
    EXPECT_FALSE( p1 );
}

TEST(VerifySolution, emptyString){

    std::string s1 = "";
    std::string s2 = "";
    std::string s3 = "";

    std::unordered_map<char, unsigned> puzzle = {  };

    bool p1 = puzzleSolver(s1, s2, s3, puzzle);

    EXPECT_TRUE( p1 & gradeYesAnswer(s1, s2, s3,  puzzle) );
} 

TEST(VerifySolution, halfEmptyString1){

    std::string s1 = "A";
    std::string s2 = "";
    std::string s3 = "";

    std::unordered_map<char, unsigned> puzzle = {};

    bool p1 = puzzleSolver(s1, s2, s3, puzzle);

    EXPECT_TRUE( p1 & gradeYesAnswer(s1, s2, s3,  puzzle) );
} 

TEST(VerifySolution, halfEmptyString2){

    std::string s1 = "";
    std::string s2 = "B";
    std::string s3 = "";

    std::unordered_map<char, unsigned> puzzle = {};

    bool p1 = puzzleSolver(s1, s2, s3, puzzle);

    EXPECT_TRUE( p1 & gradeYesAnswer(s1, s2, s3,  puzzle) );
} 

TEST(VerifySolution, halfEmptyString3){

    std::string s1 = "";
    std::string s2 = "";
    std::string s3 = "C";

    std::unordered_map<char, unsigned> puzzle = {};

    bool p1 = puzzleSolver(s1, s2, s3, puzzle);

    EXPECT_TRUE( p1 & gradeYesAnswer(s1, s2, s3,  puzzle) );
} 

TEST(VerifySolution, longerThirdString){

    std::string s1 = "AB";
    std::string s2 = "B";
    std::string s3 = "C";

    std::unordered_map<char, unsigned> puzzle = {};

    bool p1 = puzzleSolver(s1, s2, s3, puzzle);

    EXPECT_TRUE( p1 & gradeYesAnswer(s1, s2, s3,  puzzle) );
} 

TEST(VerifySolution, testingTheOldTestOriginatedFromMainFunction){

    std::string s1 = "ACC";
    std::string s2 = "CBA";
    std::string s3 = "DFG";

    std::unordered_map<char, unsigned> puzzle = {};

    bool p1 = puzzleSolver(s1, s2, s3, puzzle);

    EXPECT_TRUE( p1 & gradeYesAnswer(s1, s2, s3,  puzzle) );
} 

TEST(MediumTest, testFromProj0_1){

    std::string s1 = "AAAAAAAAAAAAA";
    std::string s2 = "OOOOOOOOOOOOO";
    std::string s3 = "IIIIIIIIIIIII";

    std::unordered_map<char, unsigned> puzzle = {};

    bool p1 = puzzleSolver(s1, s2, s3, puzzle);

    EXPECT_TRUE( p1 & gradeYesAnswer(s1, s2, s3,  puzzle) );
} 
TEST(MediumTest, testFromProj0_2){

    std::string s1 = "AAAAAAAAAAAAA";
    std::string s2 = "OOOOOOOOOOOOO";
    std::string s3 = "IIIIIIIIIIIIDD";

    std::unordered_map<char, unsigned> puzzle = {};

    bool p1 = puzzleSolver(s1, s2, s3, puzzle);

    EXPECT_FALSE( p1 & gradeYesAnswer(s1, s2, s3,  puzzle) );
} 
TEST(MediumTest, testFromProj0_3){

    std::string s1 = "GP";
    std::string s2 = "AT";
    // s1 + s2 = 1013413
    // 1013413 = DTDPODP
    std::string s3 = "DDP";

    std::unordered_map<char, unsigned> puzzle = {};

    bool p1 = puzzleSolver(s1, s2, s3, puzzle);

    EXPECT_TRUE( p1 & gradeYesAnswer(s1, s2, s3,  puzzle) );
} 
TEST(MediumTest, testFromProj0_4){

    std::string s1 = "DGP";
    std::string s2 = "CAT";
    std::string s3 = "ODP";

    std::unordered_map<char, unsigned> puzzle = {};

    bool p1 = puzzleSolver(s1, s2, s3, puzzle);

    EXPECT_TRUE( p1 & gradeYesAnswer(s1, s2, s3,  puzzle) );
} 
TEST(MediumTest, testFromProj0_5){

    std::string s1 = "CDGP";
    std::string s2 = "DCAT";
    std::string s3 = "PODP";

    std::unordered_map<char, unsigned> puzzle = {};

    bool p1 = puzzleSolver(s1, s2, s3, puzzle);

    EXPECT_TRUE( p1 & gradeYesAnswer(s1, s2, s3,  puzzle) );
} 
TEST(MediumTest, testFromProj0_6){

    std::string s1 = "ACDGP";
    std::string s2 = "GDCAT";
    std::string s3 = "DDPODP";

    std::unordered_map<char, unsigned> puzzle = {};

    bool p1 = puzzleSolver(s1, s2, s3, puzzle);

    EXPECT_TRUE( p1 & gradeYesAnswer(s1, s2, s3,  puzzle) );
} 
TEST(MediumTest, testFromProj0_6_reverse){

    std::string s2 = "ACDGP";
    std::string s1 = "GDCAT";
    std::string s3 = "DDPODP";

    std::unordered_map<char, unsigned> puzzle = {};

    bool p1 = puzzleSolver(s1, s2, s3, puzzle);

    EXPECT_TRUE( p1 & gradeYesAnswer(s1, s2, s3,  puzzle) );
} 
TEST(MediumTest, testFromProj0_7){

    std::string s1 = "ACDGP";
    std::string s2 = "IGDCAT";
    std::string s3 = "JDPODP";

    std::unordered_map<char, unsigned> puzzle = {};

    bool p1 = puzzleSolver(s1, s2, s3, puzzle);

    EXPECT_TRUE( p1 & gradeYesAnswer(s1, s2, s3,  puzzle) );
} 
TEST(MediumTest, testFromProj0_8){

    std::string s1 =   "ACDGP";
    std::string s2 =  "IGDCAT"; // I = 9
    std::string s3 = "DTDPODP";

    std::unordered_map<char, unsigned> puzzle = {};

    bool p1 = puzzleSolver(s1, s2, s3, puzzle);

    EXPECT_TRUE( p1 & gradeYesAnswer(s1, s2, s3,  puzzle) );
} 
TEST(MediumTest, testFromProj0_9){

    std::string s2 =   "ACDGP";
    std::string s1 =  "IGDCAT"; // I = 9
    std::string s3 = "DTDPODP";

    std::unordered_map<char, unsigned> puzzle = {};

    bool p1 = puzzleSolver(s1, s2, s3, puzzle);

    EXPECT_TRUE( p1 & gradeYesAnswer(s1, s2, s3,  puzzle) );
} 
TEST(MediumTest, testFromProj0_10){

    std::string s1 = "AC"; // 52
    std::string s2 = "IIOPTACDIIOG"; // 994305219946
    // s1 + s2 = 994305219998
    // 994305219998 = DTDPODP
    std::string s3 = "IIOPTACDIIIK";

    std::unordered_map<char, unsigned> puzzle = {};

    bool p1 = puzzleSolver(s1, s2, s3, puzzle);

    EXPECT_TRUE( p1 & gradeYesAnswer(s1, s2, s3,  puzzle) );
} 
TEST(MediumTest, testFromProj0_11){

    std::string s2 = "AC"; // 52
    std::string s1 = "IIOPTACDIIOG"; // 994305219946
    // s1 + s2 = 994305219998
    // 994305219998 = DTDPODP
    std::string s3 = "IIOPTACDIIIK";

    std::unordered_map<char, unsigned> puzzle = {};

    bool p1 = puzzleSolver(s1, s2, s3, puzzle);

    EXPECT_TRUE( p1 & gradeYesAnswer(s1, s2, s3,  puzzle) );
} 

TEST(MediumTest, testFromProj0_12){

    std::string s1 = "";
    std::string s2 = "IIOPTACDIIOG";
    // s1 + s2 = 994305219946
    // 994305219946 = IIOPTACDIIOG
    std::string s3 = "IIOPTACDIIOG";

    std::unordered_map<char, unsigned> puzzle = {};

    bool p1 = puzzleSolver(s1, s2, s3, puzzle);

    EXPECT_TRUE( p1 & gradeYesAnswer(s1, s2, s3,  puzzle) );
} 
TEST(OtherEdgeCases, edgeCase1){

    std::string s1 = "ABABK";
    std::string s2 = "IIIIIIIBABAC";
    // ABABK = 12129
    // BABAC = 21213
    // CCCDB = 33342
    std::string s3 = "IIIIIIICCCDB";

    std::unordered_map<char, unsigned> puzzle = {};

    bool p1 = puzzleSolver(s1, s2, s3, puzzle);

    EXPECT_TRUE( p1 & gradeYesAnswer(s1, s2, s3,  puzzle) );
} 



} // end namespace
