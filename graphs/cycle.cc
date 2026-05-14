#include<cstdint>
#include <iostream>
#include <vector>

using ull = uint64_t;
using ll = int64_t;

const int MOD = 1e9 + 7;
const ll LINF = 1e18 + 7;
const int INF = 1e9 + 7;

template <typename T>
using Vec = std::vector<T>;

int main() {
    int n, m;
    std::cin >> n >> m;

    Vec<Vec<int>> G(n+1);
    for (int i = 0; i < m; i++) {
        int x, y;
        scanf ("%d%d", &x, &y);
        G[x].push_back (y);
        G[y].push_back (x);
    }

}
