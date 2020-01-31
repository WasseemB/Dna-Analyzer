#include <iostream>
#include "DnaSequence.h"
#include <gtest/gtest.h>
#include "File.h"
#include "gmock/gmock-matchers.h"
#include "gmock/gmock-more-matchers.h"

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

TEST(DnaSequence, sliceString) {
    DnaSequence dnaSequence("AGTTGAAGTTGA");
    ASSERT_EQ(dnaSequence.getSlicedSequence(0, 3), "AGT");
}

TEST(DnaSequence, reversePair) {
    DnaSequence dnaSequence("GTGC");
    ASSERT_STREQ(dnaSequence.reversePair().getSequence(), "GCAC");
}

TEST(File, readFile) {
    File f;
    string in = "this a read and write test";
    f.writeFile("output", in.c_str());
    string out = f.readFile("output");
    ASSERT_EQ(in, out);
}

TEST(DnaSequence, seqFind) {
    DnaSequence dnaSequence("AGTCGAC");
    ASSERT_EQ(dnaSequence.findSubSequence("TCG"), 2);
}

TEST(DnaSequence, seqFindF) {
    DnaSequence dnaSequence("AGTCGAC");
    ASSERT_NE(dnaSequence.findSubSequence("AAA"), 2);
}

TEST(DnaSequence, seqFindFT) {
    DnaSequence dnaSequence("AGTCGAC");
    ASSERT_EQ(dnaSequence.findSubSequence("TTT"), -1);
}

TEST(DnaSequence, seqCount) {
    DnaSequence dnaSequence("AGTCGACGTCAAGTC");
    ASSERT_EQ(dnaSequence.getSubSequenceCount("GTC"), 3);
}

TEST(DnaSequence, seqSub) {
    DnaSequence dnaSequence("AGTCGACGTCAAGTC");
    ASSERT_THAT(dnaSequence.findAllSubSequence("AGT"), testing::ElementsAre(0, 11));
}

TEST(DnaSequence, cons) {
    DnaSequence dnaSequence("AATGTAGTAGTAATGA");
    vector<string> res = dnaSequence.findConsensus();
    vector<string> expectedRes;
    expectedRes.push_back("ATGTAG");
    expectedRes.push_back("ATGTAGTAG");
    expectedRes.push_back("ATGTAGTAGTAA");
    expectedRes.push_back("ATGTAGTAGTAATGA");
    ASSERT_THAT(res, ::testing::ContainerEq(expectedRes));


}

