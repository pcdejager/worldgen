#include "pch.h"
#include "..\Marry.h"

TEST(MarryTest, Constructor)
{
    std::map<__int64, double> maleMap;
    maleMap.insert(std::make_pair(1LL, 1.1));
    std::map<__int64, double> femaleMap;
    Marry test(maleMap, femaleMap);
    EXPECT_EQ(test.Test_Male().size(), 1u);
    EXPECT_EQ(test.Test_Female().size(), 0u);
}