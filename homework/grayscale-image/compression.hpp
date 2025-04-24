#pragma once
#include <algorithm>
#include <array>
#include <cstdint>
#include <map>
#include <vector>

constexpr std::size_t width = 32;
constexpr std::size_t height = 32;

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, width>, height>& bitimg);
std::array<std::array<uint8_t, width>, height> decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>>& bitimg);