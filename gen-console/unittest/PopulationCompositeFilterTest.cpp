#include "pch.h"
#include "..\PopulationCompositeFilter.h"

class TestPopulationCompositeFilter : public IPopulationFilter
{
public:
    TestPopulationCompositeFilter()
        : counter(0)
    {
        ;
    }

    virtual ~TestPopulationCompositeFilter()
    {
        ;
    }

public:
    virtual bool Allow(Individual* individual)
    {
        ++counter;
        if (counter % 2 == 0)
        {
            return true;
        }
        return false;
    }

public:
    int counter;
};

TEST(PopulationCompositeFilterTest, Constructor)
{
    PopulationCompositeFilter test;
    ASSERT_EQ(test.Filters().size(), 0);
}

TEST(PopulationCompositeFilterTest, Allow)
{
    IPopulationFilterPtr filter1 = IPopulationFilterPtr(new TestPopulationCompositeFilter());
    TestPopulationCompositeFilter* testFilter1 = dynamic_cast<TestPopulationCompositeFilter*>(filter1.get());
    IPopulationFilterPtr filter2 = IPopulationFilterPtr(new TestPopulationCompositeFilter());
    TestPopulationCompositeFilter* testFilter2 = dynamic_cast<TestPopulationCompositeFilter*>(filter2.get());

    PopulationCompositeFilter test;
    test.AddFilter(filter1);
    test.AddFilter(filter2);
    ASSERT_EQ(test.Filters().size(), 2);
    EXPECT_EQ(test.Filters()[0], filter1);
    EXPECT_EQ(test.Filters()[1], filter2);

    test.Allow(nullptr);
    EXPECT_EQ(testFilter1->counter, 1);
    EXPECT_EQ(testFilter2->counter, 0);

    test.Allow(nullptr);
    EXPECT_EQ(testFilter1->counter, 2);
    EXPECT_EQ(testFilter2->counter, 1);

    test.Allow(nullptr);
    EXPECT_EQ(testFilter1->counter, 3);
    EXPECT_EQ(testFilter2->counter, 1);

    test.Allow(nullptr);
    EXPECT_EQ(testFilter1->counter, 4);
    EXPECT_EQ(testFilter2->counter, 2);
}

TEST(PopulationCompositeFilterTest, AddFilter)
{
    IPopulationFilterPtr filter1 = IPopulationFilterPtr(new TestPopulationCompositeFilter());
    IPopulationFilterPtr filter2 = IPopulationFilterPtr(new TestPopulationCompositeFilter());

    PopulationCompositeFilter test;
    ASSERT_EQ(test.Filters().size(), 0);

    test.AddFilter(filter1);
    ASSERT_EQ(test.Filters().size(), 1);
    EXPECT_EQ(test.Filters()[0], filter1);

    test.AddFilter(filter2);
    ASSERT_EQ(test.Filters().size(), 2);
    EXPECT_EQ(test.Filters()[0], filter1);
    EXPECT_EQ(test.Filters()[1], filter2);
}