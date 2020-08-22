#pragma once

class Sex
{
private:
    Sex() = delete;
public:
    Sex(bool isMale, bool isFemale, bool isFertile);
    Sex(const Sex& rhs) = default;
    ~Sex() = default;
    Sex& operator=(const Sex& rhs) = default;

public:
    bool IsMale() const { return male; }
    bool IsFemale() const { return female; }
    bool IsFertile() const { return fertile; }

private:
    bool male;
    bool female;
    bool fertile;
};

