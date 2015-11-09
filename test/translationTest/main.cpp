#include "gtest/gtest.h"
#include "translator.h"
#include <string>

using namespace std;

Translator translator;

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    int ret = RUN_ALL_TESTS();
    return ret;
}

TEST(TranslationTest, Start) {
    EXPECT_EQ(1, 1*1);
}

TEST(TranslationTest, CanTranslateEmptyString) {
    string translation = translator.translate("");
    EXPECT_EQ(translation, "");
}

TEST(TranslationTest, CanTranslateASimpleTerm) {
    string translation = translator.translate("x");
    EXPECT_EQ(translation, "x");
}

TEST(TranslationTest, CanTranslateAnExponential) {
    string translation = translator.translate("x^2");
    EXPECT_EQ(translation, "x a la 2");
    translation = translator.translate("y^3");
    EXPECT_EQ(translation, "y a la 3");
}