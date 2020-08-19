#include "pch.h"
#include "../ConfigLoader.h"
#include "../TimeSpan.h"
TEST(ConfigLoaderTest, ConvertToInt_int)
{
    std::vector<std::wstring> empty;
    ConfigLoader loader(empty);
    std::wstring value1 = L"123";
    EXPECT_EQ(123L, loader.ConvertToInt(value1));
}

TEST(ConfigLoaderTest, ConvertToInt_duration)
{
    std::vector<std::wstring> empty;
    ConfigLoader loader(empty);

    // Y
    std::wstring value = L"D12345Y";
    TimeSpan span(12345L, 0L, 0L, 0L, 0L, false);
    EXPECT_EQ(span.Ticks(), loader.ConvertToInt(value));

    // YD
    value = L"D1234Y5D";
    span = TimeSpan(1234L, 5L, 0L, 0L, 0L, false);
    EXPECT_EQ(span.Ticks(), loader.ConvertToInt(value));

    // YH
    value = L"D1234Y5H";
    span = TimeSpan(1234L, 0L, 5L, 0L, 0L, false);
    EXPECT_EQ(span.Ticks(), loader.ConvertToInt(value));

    // YM
    value = L"D1234Y5M";
    span = TimeSpan(1234L, 0L, 0L, 5L, 0L, false);
    EXPECT_EQ(span.Ticks(), loader.ConvertToInt(value));

    // YS
    value = L"D1234Y5S";
    span = TimeSpan(1234L, 0L, 0L, 0L, 5L, false);
    EXPECT_EQ(span.Ticks(), loader.ConvertToInt(value));

    // YDH
    value = L"D123Y4D5H";
    span = TimeSpan(123L, 4L, 5L, 0L, 0L, false);
    EXPECT_EQ(span.Ticks(), loader.ConvertToInt(value));

    // YDM
    value = L"D123Y4D5M";
    span = TimeSpan(123L, 4L, 0L, 5L, 0L, false);
    EXPECT_EQ(span.Ticks(), loader.ConvertToInt(value));

    // YDS
    value = L"D123Y4D5S";
    span = TimeSpan(123L, 4L, 0L, 0L, 5L, false);
    EXPECT_EQ(span.Ticks(), loader.ConvertToInt(value));

    // YHM
    value = L"D123Y4H5M";
    span = TimeSpan(123L, 0L, 4L, 5L, 0L, false);
    EXPECT_EQ(span.Ticks(), loader.ConvertToInt(value));

    // YHS
    value = L"D123Y4H5S";
    span = TimeSpan(123L, 0L, 4L, 0L, 5L, false);
    EXPECT_EQ(span.Ticks(), loader.ConvertToInt(value));

    // YMS
    value = L"D123Y4M5S";
    span = TimeSpan(123L, 0L, 0L, 4L, 5L, false);
    EXPECT_EQ(span.Ticks(), loader.ConvertToInt(value));

    // YDHM
    value = L"D12Y3D4H5M";
    span = TimeSpan(12L, 3L, 4L, 5L, 0L, false);
    EXPECT_EQ(span.Ticks(), loader.ConvertToInt(value));

    // YDHS
    value = L"D12Y3D4H5S";
    span = TimeSpan(12L, 3L, 4L, 0L, 5L, false);
    EXPECT_EQ(span.Ticks(), loader.ConvertToInt(value));

    // YDMS
    value = L"D12Y3D4M5S";
    span = TimeSpan(12L, 3L, 0L, 4L, 5L, false);
    EXPECT_EQ(span.Ticks(), loader.ConvertToInt(value));

    // YHMS
    value = L"D12Y3H4M5S";
    span = TimeSpan(12L, 0L, 3L, 4L, 5L, false);
    EXPECT_EQ(span.Ticks(), loader.ConvertToInt(value));

    // YDHMS
    value = L"D1Y2D3H4M5S";
    span = TimeSpan(1L, 2L, 3L, 4L, 5L, false);
    EXPECT_EQ(span.Ticks(), loader.ConvertToInt(value));

    // D
    value = L"D1234D";
    span = TimeSpan(0L, 1234L, 0L, 0L, 0L, false);
    EXPECT_EQ(span.Ticks(), loader.ConvertToInt(value));

    // DH
    value = L"D123D4H";
    span = TimeSpan(0L, 123L, 4L, 0L, 0L, false);
    EXPECT_EQ(span.Ticks(), loader.ConvertToInt(value));

    // DM
    value = L"D123D4M";
    span = TimeSpan(0L, 123L, 0L, 4L, 0L, false);
    EXPECT_EQ(span.Ticks(), loader.ConvertToInt(value));

    // DS
    value = L"D123D4S";
    span = TimeSpan(0L, 123L, 0L, 0L, 4L, false);
    EXPECT_EQ(span.Ticks(), loader.ConvertToInt(value));

    // DHM
    value = L"D12D3H4M";
    span = TimeSpan(0L, 12L, 3L, 4L, 0L, false);
    EXPECT_EQ(span.Ticks(), loader.ConvertToInt(value));

    // DHS
    value = L"D12D3H4S";
    span = TimeSpan(0L, 12L, 3L, 0L, 4L, false);
    EXPECT_EQ(span.Ticks(), loader.ConvertToInt(value));

    // DMS
    value = L"D12D3M4S";
    span = TimeSpan(0L, 12L, 0L, 3L, 4L, false);
    EXPECT_EQ(span.Ticks(), loader.ConvertToInt(value));

    // DHMS
    value = L"D1D2H3M4S";
    span = TimeSpan(0L, 1L, 2L, 3L, 4L, false);
    EXPECT_EQ(span.Ticks(), loader.ConvertToInt(value));

    // H
    value = L"D123H";
    span = TimeSpan(0L, 0L, 123L, 0L, 0L, false);
    EXPECT_EQ(span.Ticks(), loader.ConvertToInt(value));

    // HM
    value = L"D12H3M";
    span = TimeSpan(0L, 0L, 12L, 3L, 0L, false);
    EXPECT_EQ(span.Ticks(), loader.ConvertToInt(value));

    // HS
    value = L"D12H3S";
    span = TimeSpan(0L, 0L, 12L, 0L, 3L, false);
    EXPECT_EQ(span.Ticks(), loader.ConvertToInt(value));

    // HMS
    value = L"D1H2M3S";
    span = TimeSpan(0L, 0L, 1L, 2L, 3L, false);
    EXPECT_EQ(span.Ticks(), loader.ConvertToInt(value));

    // M
    value = L"D12M";
    span = TimeSpan(0L, 0L, 0L, 12L, 0L, false);
    EXPECT_EQ(span.Ticks(), loader.ConvertToInt(value));

    // MS
    value = L"D1M2S";
    span = TimeSpan(0L, 0L, 0L, 1L, 2L, false);
    EXPECT_EQ(span.Ticks(), loader.ConvertToInt(value));

    // S
    value = L"D1S";
    span = TimeSpan(0L, 0L, 0L, 0L, 1L, false);
    EXPECT_EQ(span.Ticks(), loader.ConvertToInt(value));
}