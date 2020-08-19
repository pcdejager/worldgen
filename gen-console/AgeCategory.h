#pragma once

enum class AgeCategory { NewBorn, Toddler, Child, Teenager, YoungAdult, Adult, OldAdult, Elder, Dead };

class AgeCategoryUtils
{
private:
    AgeCategoryUtils() = delete;
    ~AgeCategoryUtils() = delete;

public:
    static AgeCategory CategoryBefore(AgeCategory age);
    static AgeCategory CategoryAfter(AgeCategory age);
};

