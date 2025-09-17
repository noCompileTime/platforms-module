#pragma once

namespace windows::constants
{
    constexpr auto      acceleration = 0x2003;
    constexpr auto full_acceleration = 0x2027;

    constexpr auto    samples        = 0x2042;
    constexpr auto    samples_buffer = 0x2041;
    constexpr auto     double_buffer = 0x2011;
    constexpr auto       srgb_buffer = 0x20a9;

    constexpr auto    draw_to_window = 0x2001;
    constexpr auto    support_opengl = 0x2010;

    constexpr auto        color_type = 0x2013;
    constexpr auto              rgba = 0x202b;
    constexpr auto        color_bits = 0x2014;
    constexpr auto        depth_bits = 0x2022;
    constexpr auto      stencil_bits = 0x2023;
}