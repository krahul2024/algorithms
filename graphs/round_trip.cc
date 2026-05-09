#include <iostream>
#include <vector>

#define VI  std::vector<int>
#define VB  std::vector<bool>
#define VVI std::vector<std::vector<int>>
#define PI  std::pair<int, int>

void dfs (const VVI& G, VI& parent, VI& vis, int x, int& start, int& end) {
    vis[x] = 1;

    for (const auto& ch: G[x]) {
        if (!vis[ch]) {
            parent[ch] = x;
            dfs (G, parent, vis, ch, start, end);
        } else if (vis[ch] == 1 && ch != parent[x]) { // cycle
            start = x;
            end = ch;
            vis[ch] = 2;
            break;
        }
    }

    vis[x] = 2;
}

int main() {
    int n, m;
    std::cin >> n >> m;

    VVI G(n+1);
    VI vis(n+1, 0);
    VI parent(n+1, -1);

    for (int i = 0; i < m; i++) {
        int x, y;
        scanf ("%d%d", &x, &y);

        G[x].push_back (y);
        G[y].push_back (x);
    }

    int start = -1, end = -1;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs (G, parent, vis, i, start, end);

            if (start > 0 && end > 0)
                break;
            else
                start = -1, end = -1;
        }
    }

    VI cities;
    if (start > 0 && end > 0) {
        int vert = start;

        while (vert != end) {
            cities.push_back (vert);
            vert = parent[vert];
        }

        cities.push_back (vert);
        cities.push_back (start);

        std::cout << cities.size() << '\n';
        for (auto c: cities)
            std::cout << c << ' ';

        std::cout << '\n';
    } else {
        std::cout << "IMPOSSIBLE\n";
    }
}
