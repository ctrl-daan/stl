#include "compression.hpp"

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, width>, height>& bitimg) {
    std::vector<std::pair<uint8_t, uint8_t>> compressed;

    std::for_each(bitimg.begin(), bitimg.end(), [&compressed](auto& column) {
        int count = 1;
        std::for_each(std::next(column.begin()), column.end(), [&compressed, &count, &column](auto& pixel) {
            int row = std::distance(column.begin(), &pixel);
            if (pixel == column[row - 1]) {
                count++;
            } else {
                compressed.push_back({column[row - 1], count});
                count = 1;
            }
            if (row == column.size() - 1) {
                compressed.push_back({pixel, count});
            }
        });
    });

    return compressed;
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>>& compressed) {
    std::array<std::array<uint8_t, width>, height> decompressed;
    
    int index = 0;
    std::for_each(compressed.begin(), compressed.end(), [&decompressed, &index](const std::pair<uint8_t, uint8_t>& c) {
        uint8_t value = c.first;
        uint8_t count = c.second;
        std::generate_n(&decompressed[index / height][index % height], count, [value]() { return value; });
        index += count;
    });

    return decompressed;
}