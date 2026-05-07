#include <algorithm>
#include <iostream>
#include <vector>

void recurse (const std::vector<std::vector<int>>& g, std::vector<bool>& vis, int x, std::vector<int>& parent) {
    vis[x] = true;

    for (auto& ch: g[x]) {
        if (!vis[ch]) {
            parent[ch] = parent[x];
            recurse (g, vis, ch, parent);
        }
    }
}

int main() {
    int n, m;
    scanf ("%d%d", &n, &m);

    std::vector<std::vector<int>> g(n+1);
    std::vector<bool> vis(n+1, false);
    std::vector<int> parent(n+1, -1);

    for (int i = 0; i < m; i++) {
        int x, y;
        scanf ("%d%d", &x, &y);

        g[x].push_back (y);
        g[y].push_back (x);
    }

    std::vector<int> unique_ps;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            parent[i] = i;
            unique_ps.push_back(i);
            recurse (g, vis, i, parent);
        }
    }

    std::cout << unique_ps.size() - 1 << "\n";
    if (unique_ps.size() > 1) {
        int prev = unique_ps[0];
        for (int i = 1; i < unique_ps.size(); i++) {
            std::cout << prev << " " << unique_ps[i] << '\n';
            prev = unique_ps[i];
        }
    }
}
