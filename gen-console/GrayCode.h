#pragma once

class GrayCode
{
private:
    GrayCode() = delete;
    ~GrayCode() = delete;
public:
    static __int64 BinaryToGray(__int64 binary);
    static __int64 GrayToBinary(__int64 code);
};

