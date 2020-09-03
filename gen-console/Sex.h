#pragma once

class Sex
{
private:
    Sex() = delete;
public:
    Sex(bool isMale, bool isFemale, double fertile);
    Sex(const Sex& rhs) = default;
    ~Sex() = default;
    Sex& operator=(const Sex& rhs) = default;

public:
    bool IsMale() const { return male; }
    bool IsFemale() const { return female; }
    bool IsFertile() const;

private:
    bool male;
    bool female;
    double fertility;
};

