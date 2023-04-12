#include <iostream>
#include <string>
#include "../static/enum.cpp"

std::string generateText(typeOfText type, size_t length) {
    std::srand(time(nullptr));
    std::string text;
    switch (type) {
        case BINARY: {
            char alphabet[2] = {'0', '1'};
            char *chars = new char[length];
            for (size_t i = 0; i < length; ++i) {
                chars[i] = alphabet[std::rand() % 2];
            }
            text.assign(chars);
            delete[] chars;
            break;
        }

        case DNKTEXT: {
            char alphabet[4] = {'A', 'B', 'C', 'D'};
            char *chars = new char[length];
            for (size_t i = 0; i < length; ++i) {
                chars[i] = alphabet[std::rand() % 4];
            }
            text.assign(chars);
            delete[] chars;
            break;
        }
    }
    return text;
}

std::string generateTemplate(const std::string &text, int index, int size) {
    return text.substr(index, size);
}
