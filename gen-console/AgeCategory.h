#pragma once

// Need to add unborn category!

enum class AgeCategory { NewBorn, Toddler, Child, Teenager, YoungAdult, Adult, OldAdult, Elder, Dead };

class AgeCategoryUtils
{
private:
    AgeCategoryUtils() = delete;
    ~AgeCategoryUtils() = delete;

public:
    static AgeCategory CategoryBefore(AgeCategory age);
    static AgeCategory CategoryAfter(AgeCategory age);
    static std::vector<AgeCategory> AliveCategories();
    static std::vector<AgeCategory> MarryCategories();
    static std::vector<AgeCategory> PregnantCategories();
};

