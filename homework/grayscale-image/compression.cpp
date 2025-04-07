#include "compression.hpp"

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, width>, height>& bitimg) {
    std::vector<std::pair<uint8_t, uint8_t>> compressed;

    for (int i = 0; i < width; i++) {
        int count = 1;
        for (int j = 1; j < height; j++) {
            if (bitimg[i][j] == bitimg[i][j - 1]) {
                count++;
            } else {
                compressed.push_back({bitimg[i][j - 1], count});
                count = 1;
            }
        }
        compressed.push_back({bitimg[i][width - 1], count});
    }

    return compressed;
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>>& bitimg) {
    std::array<std::array<uint8_t, width>, height> decompressed;
    int index = 0;

    for (const auto& c : bitimg) {
        int value = c.first;
        int count = c.second;

        for (int i = 0; i < count; i++) {
            int row = index / height;
            int col = index % height;
            decompressed[row][col] = value;
            index++;
        }
    }

    return decompressed;
}
