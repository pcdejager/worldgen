#include "pch.h"
#include "..\Race.h"
#include "..\RacialTraits.h"

TEST(RaceTest, Constructor)
{
    RacialTraits traits;
    Race test(L"Test", traits);
    EXPECT_EQ(test.Name(), L"Test");
}