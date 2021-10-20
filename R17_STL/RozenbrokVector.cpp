#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    size_t n = 0;
    size_t d = 0;

    std::cout << "input n -> ";
    std::cin >> n;

    std::cout << "input d -> ";
    std::cin >> d;

    // Init x with random data.
    std::vector<std::vector<int>> raws(n);
    for (auto& raw : raws)
    {
        raw.resize(d);
        std::for_each(raw.begin(), raw.end(), [](int& x) { x = rand(); });
    }

    // Compute f(x) value.
    std::vector<double> answers(n);

    for (size_t i = 0; i < n; ++i)
    {
        auto& raw = raws[i];
        double& answer = answers[i];

        // Implement summ operator.
        for (size_t j = 1; j < d - 1; ++j)
        {
            answer += 100 * std::pow(raw[j + 1] - (raw[j] * raw[j]), 2) + std::pow(raw[j] - 1, 2);
        }
    }

    // Output answers
    std::cout << "Answers:\n";
    for (auto answer : answers)
    {
        std::cout << answer << '\n';
    }

    return 0;
}