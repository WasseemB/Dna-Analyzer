#include <iostream>
#include "DnaSequence.h"
#include <gtest/gtest.h>

using namespace std;

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(DnaSequence, createSequence) {
    DnaSequence dnaSequence("AGT");
    ASSERT_STREQ(dnaSequence.getSequence(), "AGT");
}

TEST(DnaSequence, createOppositePair) {
    DnaSequence dnaSequence("AGT");
    ASSERT_STREQ(dnaSequence.generatePair().getSequence(), "TCA");
}

TEST(DnaSequence, createFailure) {
    ASSERT_THROW(DnaSequence dnaSequence("AGTX"), std::invalid_argument);
}

TEST(DnaSequence, checkEqual) {
    DnaSequence dnaSequence("AGT");
    DnaSequence dnaSequence2("AGT");
    ASSERT_EQ(dnaSequence, dnaSequence2);
}

TEST(DnaSequence, checkNotEqual) {
    DnaSequence dnaSequence("AGT");
    DnaSequence dnaSequence2("GAT");
    ASSERT_NE(dnaSequence, dnaSequence2);
}

TEST(DnaSequence, checkCurrentIndex) {
    DnaSequence dnaSequence("AGT");
    char a = dnaSequence[0];
    ASSERT_EQ(a, 'A');
}

TEST(DnaSequence, checkIndexOutOfRange) {
    DnaSequence dnaSequence("AGT");
    ASSERT_THROW(dnaSequence[4], std::out_of_range);
}
