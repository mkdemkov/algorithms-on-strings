#include <iostream>
#include "text_generating/text-generating.cpp"

int main() {
   std::string binary_text_one = generateText(BINARY, 10000);
   std::string binary_text_two = generateText(BINARY, 100000);

}
