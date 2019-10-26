#include <iostream>
#include <functional>
#include <vector>
#include <cmath>
#include <algorithm> // for std::transform

int sum(int x, int y)
{
    return x + y;
}

int main()
{
    std::cout << sum(3, 4) << std::endl;
    std::function<int(int, int)> lambda_sum = [](int x, int y) {
        return x + y;
    };
    std::cout << lambda_sum(9, 8) << std::endl;

    // like "map"
    std::vector<int> nums{1, 2, 3, 4, 5, 6};
    std::vector<int> result;

    // if you want the result to be in "nums" to,
    // put nums.begin() instead of std::back_inserter(result) as the 3rd parameter
    std::transform(nums.begin(), nums.end(), std::back_inserter(result),
        [](int x) {return x * 2; });
    for (int i = 0; i < nums.size(); i++) {
        std::cout << result.at(i) << std::endl;
    }

    std::vector<int> result_copy;

    // filter
    std::copy_if(nums.begin(), nums.end(), std::back_inserter(result_copy),
        [](int x){ return x % 2; });

    for (int i = 0; i < result_copy.size(); i++) {
        std::cout << result_copy.at(i) << std::endl;
    }

    return 0;
}