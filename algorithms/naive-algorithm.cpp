#include <chrono>
#include <string>

int64_t naive_algorithm(const std::string &text, const std::string &pattern) {
    auto start_time = std::chrono::high_resolution_clock::now();

    int n = static_cast<int>(text.length());
    int m = static_cast<int>(pattern.length());
    int i = n - m;

    // так как ищем последнее вхождение, пойдем с конца начиная с позиции i, каждый раг двигаясь влево
    while (i >= 0) {
        int j = 0;
        while (j < m && text[i + j] == pattern[j]) {
            ++j;
        }
        if (j == m) {
            auto end_time = std::chrono::high_resolution_clock::now();
            return std::chrono::duration_cast<std::chrono::nanoseconds>(
                end_time - start_time).count();
        }
        --i;
    }

    auto end_time = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count();
}