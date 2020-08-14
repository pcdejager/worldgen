#include "pch.h"
#include "..\Individual.h"
#include "..\Parents.h"

TEST(IndividualTest, Constructor)
{
    Individual test(Parents::CreateNoParents(), WorldTime(123UL));
    EXPECT_EQ(WorldTime(123UL), test.Born());
    EXPECT_TRUE(test.IsValid());
}

TEST(IndividualTest, GetNullIndividual)
{
    auto test = Individual::GetNullIndividual();
    ASSERT_TRUE(test != nullptr);
    EXPECT_FALSE(test->IsValid());

    auto test2 = Individual::GetNullIndividual();
    ASSERT_TRUE(test == test2);
}

TEST(IndividualTest, Parents)
{
    Individual test(Parents::CreateNoParents(), WorldTime(123UL));
    auto parents = test.Parents();
    EXPECT_FALSE(parents->BiologicalFather()->IsValid());
    EXPECT_FALSE(parents->BiologicalMother()->IsValid());
}
TEST(IndividualTest, Age)
{
    Individual test(Parents::CreateNoParents(), WorldTime(123UL));
    EXPECT_EQ(TimeSpan(0L), test.Age(WorldTime(123UL)));
    EXPECT_EQ(TimeSpan(123L), test.Age(WorldTime(246UL)));
    EXPECT_EQ(TimeSpan(0L), test.Age(WorldTime(0UL)));
    EXPECT_TRUE(test.IsValid());
}

