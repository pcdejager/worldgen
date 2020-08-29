#include "pch.h"
#include "GrayCode.h"

/*static*/ __int64 GrayCode::BinaryToGray(__int64 binary)
{
    __int64 value = binary;
    value = value ^ (value >> 1LL);
    return value;
}

/*static*/ __int64 GrayCode::GrayToBinary(__int64 code)
{
    __int64 mask = code;
    __int64 result = code;
    while (mask > 0LL) 
    {           
        mask >>= 1LL;
        result ^= mask;
    }
    return result;
}
