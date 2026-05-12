#include <algorithm>
#include<cstdint>
#include <iostream>
#include <vector>
#include <utility>

using ull = uint64_t;
using ll = int64_t;

const int MOD = 1e9 + 7;
const ll LINF = 1e18 + 7;
const int INF = 1e9 + 7;

using Pull = std::pair<ull, ull>;
using Pll = std::pair<ll, ll>;

template<typename T>
using Vec = std::vector<T>;

template<typename T>
using Vec2d = Vec<Vec<T>>;

int main() {
    int n, m, q;
    std::cin >> n >> m >> q;

    Vec2d<ll> dist(n+1, Vec<ll>(n+1, LINF));
    for (auto i = 0; i < m; i++) {
        ll u, v, w;
        scanf ("%ld%ld%ld", &u, &v, &w);

        dist[u][v] = std::min (dist[u][v], w);
        dist[v][u] = std::min (dist[v][u], w);
    }

    for (int i = 1; i <= n; i++)
        dist[i][i] = 0;


    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] < LINF && dist[k][j] < LINF) {
                    dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    for (int i = 0; i < q; i++) {
        int u, v;
        scanf ("%d%d", &u, &v);
        std::cout << (dist[u][v] == LINF ? -1 : dist[u][v]) << '\n';
    }
}
