#include "pch.h"
#include "..\Parents.h"
#include "..\Individual.h"

TEST(ParentsTest, Constructor)
{

}

TEST(ParentsTest, CreateNoParents)
{
    auto test = Parents::CreateNoParents();
    ASSERT_TRUE(test != nullptr);
    EXPECT_FALSE(test->BiologicalFather()->IsValid());
    EXPECT_FALSE(test->BiologicalMother()->IsValid());
}

TEST(ParentsTest, BiologicalFather)
{
    IndividualPtr father = std::make_shared<Individual>(Parents::CreateNoParents());
    IndividualPtr mother = std::make_shared<Individual>(Parents::CreateNoParents());
    ASSERT_TRUE(father != mother);
    auto test = std::make_shared<Parents>(father, mother);
    EXPECT_TRUE(test->BiologicalFather() == father);
    EXPECT_TRUE(test->BiologicalFather() != mother);
}

TEST(ParentsTest, BiologicalMother)
{
    IndividualPtr father = std::make_shared<Individual>(Parents::CreateNoParents());
    IndividualPtr mother = std::make_shared<Individual>(Parents::CreateNoParents());
    ASSERT_TRUE(father != mother);
    auto test = std::make_shared<Parents>(father, mother);
    EXPECT_TRUE(test->BiologicalMother() != father);
    EXPECT_TRUE(test->BiologicalMother() == mother);
}