#include <string>
#include <chrono>
#include <vector>

int64_t KMPoptimized(const std::string &text, const std::string &pattern) {
    auto start_time = std::chrono::high_resolution_clock::now();

    std::string concatenated_str = text + "%" + pattern;
    int concatenated_str_size = static_cast<int>(concatenated_str.size());

    std::vector<int> border_array(concatenated_str_size);
    for (int i = 1; i < concatenated_str_size; ++i) {
        int border = border_array[i - 1];
        while (border > 0 && concatenated_str[i] != concatenated_str[border]) {
            border = border_array[border - 1];
        }
        if (concatenated_str[i] == concatenated_str[border]) {
            border++;
        }
        border_array[i] = border;
    }

    std::vector<int> border_suffix_array(concatenated_str_size);
    for (int i = 1; i < concatenated_str_size; ++i) {
        if (concatenated_str[border_array[i] + 1] != concatenated_str[i]) {
            border_suffix_array[i] = border_array[i];
        } else {
            border_suffix_array[i] = border_suffix_array[border_array[i]];
        }
    }

    size_t g = 0;
    size_t l = 0;
    std::vector<size_t> matches;
    while (g < pattern.size()) {
        if (pattern[g] == text[l]) {
            g++;
            l++;
            if (l == text.size()) {
                matches.emplace_back(g - l);
            }
        } else {
            if (l == 0) {
                g++;
            } else {
                l = border_suffix_array[l - 1];
            }
        }
    }

    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time);

    return duration.count();

}