#include "pch.h"
#include "GrayCode.h"

/*static*/ __int64 GrayCode::BinaryToGray(__int64 binary)
{
    __int64 value = binary;
    value = value ^ (value >> 1);
    return value;
}

/*static*/ __int64 GrayCode::GrayToBinary(__int64 code)
{
    __int64 mask = code;
    __int64 result = code;
    while (mask > 0) 
    {           
        mask >>= 1L;
        result ^= mask;
    }
    return result;
}
