#include <iostream>
#include <cstdint>
#include <vector>
#include <algorithm>

uint32_t calc(const std::vector<uint32_t> &numbers) {
    uint32_t res = 1;
    for(uint32_t i = 0; i < numbers.size(); i++) {
        if(numbers.at(i) > res)
            break;
        else
            res += numbers.at(i);
    }
    return res;
}

int main() {
    uint32_t n;
    std::cout << "Enter n: ";
    std::cin >> n;
    std::vector<uint32_t> numbers(n);
    std::cout << "Enter " << n << " numbers: ";
    for(uint32_t i = 0; i < n; i++)
        std::cin >> numbers.at(i);
    std::sort(numbers.begin(), numbers.end());    
    uint32_t res = calc(numbers);
    std::cout << "res: " << res << std::endl;
    return 0;
}