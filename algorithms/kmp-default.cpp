#include <string>
#include <chrono>

void computeLPS(std::string pattern, int *lps) {
    int m = static_cast<int>(pattern.size());
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int64_t KMPdefault(const std::string &text, const std::string &pattern) {
    int n = static_cast<int>(text.size());
    int m = static_cast<int>(pattern.size());

    // Вычисление стандартных граней
    int *lps = new int[m];
    computeLPS(pattern, lps);

    int i = n - 1; // Индекс текущего символа в тексте
    int j = m - 1; // Индекс текущего символа в шаблоне
    auto start = std::chrono::high_resolution_clock::now();
    while (i >= 0) {
        if (text[i] == pattern[j]) {
            i--;
            j--;
        }
        else {
            if (j != m - 1) {
                j = lps[j + 1];
            }
            else {
                i--;
            }
        }
        if (j < 0) {
            break;
        }
    }

    delete[] lps;

    // Возвращает время выполнения алгоритма в наносекундах
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);

    return duration.count();
}
