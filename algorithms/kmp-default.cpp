#include <string>
#include <chrono>
#include <vector>


int64_t KMPdefault(const std::string &text, const std::string &pattern) {
    auto start_time = std::chrono::high_resolution_clock::now();

    std::string str = text + "%" + pattern;
    int n = static_cast<int>(str.size());

    std::vector<int> br(n);
    for (int i = 1; i < n; ++i) {
        int k = br[i - 1];
        while (k > 0 && str[i] != str[k]) {
            k = br[k - 1];
        }
        if (str[i] == str[k]) {
            k++;
        }
        br[i] = k;
    }

    std::vector<int> brs(n);
    for (int i = 1; i < n; ++i) {
        brs[i] = (str[br[i] + 1] != str[i]) ? br[i] : brs[br[i]];
    }

    size_t g = 0, l = 0;
    std::vector<size_t> ans;
    while (g < pattern.size()) {
        if (pattern[g] == text[l]) {
            g++;
            l++;
            if (l == text.size()) {
                ans.push_back(g - l);
            }
        } else {
            if (l == 0) {
                g++;
            } else {
                l = brs[l - 1];
            }
        }
    }

    auto end_time = std::chrono::high_resolution_clock::now();
    auto elapsed_time = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time);
    return elapsed_time.count();
}

