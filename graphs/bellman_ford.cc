#include <iostream>
#include <vector>

const int INF = 1e9 + 7;

template<typename T1, typename T2>
using Pair = std::pair<T1, T2>;

template<typename T>
using Vec = std::vector<T>;

// Works for all the graph types except `negative cyclic graph`, also negative cyclic graph detection
// Shortest path from source -> all nodes, okay for negative weights
// Usage varies, not suggested to use it for every type of graphs, especially trees(undirected)

struct Edge { int u, v, w; };

int main() {
    int n, m;
    scanf ("%d%d", &n, &m);

    Vec<Edge> edges;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf ("%d%d%d", &u, &v, &w);

        edges.push_back ({ u, v, w });
        edges.push_back ({ v, u, w });
    }

    Vec<int> dist (n+1, INF);
    int source = 1;
    dist[source]= 0;

    for (int i = 1; i <= n-1; i++) {
        for (const auto& e: edges) {
            auto& [u, v, w] = e;
            if ( dist[v] > dist[u] + w  && dist[u] != INF)
                dist[v] = dist[u] + w;
        }
    }

    for (int i = 1; i <= n; i++)
        std::cout << dist[i] << ", ";

    std::cout << '\n';
}
