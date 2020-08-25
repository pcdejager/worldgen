#include "pch.h"
#include "..\Height.h"
#include "..\AgeTraits.h"
#include "..\MultiPointValue.h"
#include "..\Sex.h"

TEST(HeightTest, Constructor)
{
    __int64 year = TimeSpan(1, 0, 0, 0, 0, false).Ticks();
    MultiPointValueInt ranges({ 10L * year, 20L * year, 30L * year, 40L * year, 50L * year, 60L * year, 70L * year, 80L * year });
    AgeTraitsPtr ages = std::make_shared<AgeTraits>(ranges);
    MultiPointValueRange male({ {10, 15, 20}, {20, 25, 30}, {30, 35, 40}, {40, 45, 50}, {50, 55, 60}, {60, 65, 70}, {70, 75, 80}, {80, 85, 90} });
    MultiPointValueRange female({ {10, 15, 20}, {20, 25, 30}, {30, 35, 40}, {40, 45, 50}, {50, 55, 60}, {60, 65, 70}, {70, 75, 80}, {80, 85, 90} });
    Height test(male, female, ages);
    Sex sex(true, false, false);
    EXPECT_EQ(test.Value(TimeSpan(1, 0, 0, 0, 0, true), sex), -1L);
}