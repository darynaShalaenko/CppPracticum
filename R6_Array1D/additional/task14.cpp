#include <iostream>
#include <cstdint>
#include <vector>

std::vector<uint32_t> generateNumbers(uint32_t n) {
    std::vector<uint32_t> indexes((1 << n) - 1);
    for(uint32_t i = 1, j = 2; i < n; i++, j *= 2) {
        for(uint32_t k = (j-1); k < indexes.size(); k += j)
            indexes.at(k) = i;
    }
    std::vector<uint32_t> numbers(1 << n);
    numbers[0] = 0;
    for(uint32_t i = 1; i < numbers.size(); i++)
        numbers.at(i) = numbers.at(i-1) ^ (1 << indexes.at(i-1));
    return numbers;
}

int main() {
    uint32_t n;
    std::cout << "Enter n: ";
    std::cin >> n;
    std::vector<uint32_t> numbers = generateNumbers(n);
    std::cout << "Gray code: [";
    for(uint32_t i = 0; i < numbers.size(); i++) {
        std::cout << numbers.at(i);
        if((i+1) != numbers.size())
            std::cout << ", ";
    }
    std::cout << "]" << std::endl;
    return 0;
}