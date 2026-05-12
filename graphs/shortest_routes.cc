#include <cstdint>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>

#define PInt std::pair<uint64_t, uint64_t>
#define PIInt std::pair<uint64_t, PInt>
#define VInt std::vector<uint64_t>
#define VBool std::vector<bool>
#define VVInt std::vector<std::vector<INT>>
#define VVPInt std::vector<std::vector<std::pair<uint64_t, uint64_t>>>

const uint64_t Inf = 1e14+7;

// standard Dijkstra implementation
int main () {
    int n, m;
    std::cin >> n >> m;

    VVPInt G(n+1);
    VBool visited (n+1, false);
    VInt distance (n+1, Inf);

    for (int i = 0; i < m; i++) {
        uint64_t u, v, w;
        scanf ("%ld%ld%ld", &u, &v, &w);
        G[u].push_back ({ v, w });
    }

    uint64_t start = 1;
    distance[start] = 0;

    // <dist, node> -> <w, u>
    std::priority_queue<PInt, std::vector<PInt>, std::greater<PInt>> q;
    q.push({ distance[start], start });

    while (!q.empty()) {
        auto [w, u] = q.top();
        q.pop();

        if (visited[u])
            continue;

        visited[u] = true;

        for (auto& [v, wt]: G[u]) {
            if (distance[v] > distance[u] + wt) {
                distance[v] = distance[u] + wt;
                q.push ({ distance[v], v });
            }
        }
    }

    for (uint64_t i = 1; i <= n; i++)
        std::cout << distance[i] << ' ';

    std::cout << "\n";
}
