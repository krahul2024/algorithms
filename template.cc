#include<cstdint>
#include <iostream>
#include <vector>
#include <utility>

template<typename T1, typename T2>
using Pair = std::pair<T1, T2>;

template<typename T>
using Vec = std::vector<T>;

template<typename... Args>
void scan (Args&... args) {
    ((std::cin >> args), ...);
}

using ull = uint64_t;
using ll = int64_t;

const int MOD = 1e9 + 7;
const ll LINF = 1e18 + 7;
const int INF = 1e9 + 7;

