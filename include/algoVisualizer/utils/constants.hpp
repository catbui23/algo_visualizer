#pragma once

#include <chrono>
#include <string_view>
#include <unordered_set>

using namespace std;

namespace ANSI_COLOR {
inline constexpr string_view RESET = "\e[0;37m";
inline constexpr string_view GREEN = "\e[0;32m";
inline constexpr string_view RED = "\e[0;31m";
inline constexpr string_view YELLOW = "\e[0;33m";
}; // namespace ANSI_COLOR

constexpr chrono::duration REFRESH_TIME = chrono::milliseconds(50);
