#include <iostream>
#include "text_generating/text-generating.cpp"
#include "algorithms/naive-algorithm.cpp"
#include "algorithms/kmp-default.cpp"
#include "static/file-writer.cpp"

int main() {
    std::ofstream table("../tables/table.csv");
    table << "Type of text;" << "Algorithm;" << "Pattern size;" << "Time(ns)\n";
    std::srand(time(nullptr));
    std::string binary_text_one = generateText(BINARY, 10000);
    std::string binary_text_two = generateText(BINARY, 100000);

    // цикл который отвечает за размер искомого шаблона
    for (int i = 100; i <= 3000; i += 100) {
        std::string template_from_text = generateTemplate(binary_text_one, std::rand() % 10000, i);
        // теперь прогонвяем по трем алгоритмам

        int64_t total_time = 0;
        // усредняем общее время, прогнав тесты по 3 раза
        for (int j = 0; j < 3; ++j) {
            total_time += naive_algorithm(binary_text_one, template_from_text);
        }
        int64_t avg_time = total_time / 3;
        table << "бинарный;" << "наивный;" << i << ";" << avg_time << "\n";

        total_time = 0;
        for (int j = 0; j < 3; ++j) {
            total_time += KMPdefault(binary_text_one, template_from_text);
        }
        avg_time = total_time / 3;
        table << "бинарный;" << "КМП-обычный;" << i << ";" << avg_time << "\n";
    }

    std::cout << binary_text_one.size() << "\n" << binary_text_two.size();
}
