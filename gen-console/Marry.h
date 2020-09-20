#pragma once

class Marry
{
public:
    Marry(const std::map<__int64, double>& marryMale, const std::map<__int64, double>& marryFemale);
    ~Marry() = default;

public:
    double ChanceToMarryMale(__int64 raceID);
    double ChanceToMarryFemale(__int64 raceID);

public:
    void Log() const;

#ifdef UNITTEST
public:
    std::map<__int64, double>& Test_Male() { return male; }
    std::map<__int64, double>& Test_Female() { return female; }
#endif

private:
    std::map<__int64, double> male;
    std::map<__int64, double> female;
};

