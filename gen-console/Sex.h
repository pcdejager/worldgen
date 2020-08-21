#pragma once

class Sex
{
private:
    Sex() = delete;
public:
    Sex(bool isMale, bool isFemale);
    Sex(const Sex& rhs) = default;
    ~Sex() = default;
    Sex& operator=(const Sex& rhs) = default;

public:
    bool IsMale() const { return male; }
    bool IsFemale() const { return female; }

private:
    bool male;
    bool female;
};

