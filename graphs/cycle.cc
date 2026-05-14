#include<cstdint>
#include <iostream>
#include <vector>
#include <functional>

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

    Vec<bool> vis (n+1, false);
    bool cycle_found = false;

    std::function<void(int, int)> has_cycle = [&](int u, int p) -> void {
        vis[u] = true;

        for (const auto& v: G[u]) {
            if (vis[v] && v != p) {
                cycle_found = true;
                break;
            } else if (!vis[v]){
                has_cycle (v, u);
            }
        }
    };

    for (int i = 1; i <= n; i++) {
        if (!vis[i])
            has_cycle (i, -1);

        if (cycle_found) {
            std::cout << "Cycle Found\n";
            break;
        }
    }

    if (!cycle_found)
        std::cout << "No Cycle found\n";
}

// NOTE: If an undirected graph is not tree(#vertices = n, #edges(m) = n-1), then it contains at least one cycle.
