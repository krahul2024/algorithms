#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> G(n+1);
    std::vector<int> parent (n+1, -1);
    std::vector<bool> visited (n+1, false);

    for (int i = 0; i < m; i++) {
        int x, y;
        scanf ("%d%d", &x, &y);
        G[x].push_back (y);
        G[y].push_back (x);
    }

    bool found = false;
    std::queue<int> q;
    q.push (1);
    parent [1] = 1;
    visited[1] = true;

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        if (x == n) {
            found = true;
            break;
        } else {
            for (const auto& ch: G[x]) {
                if (!visited[ch]) {
                    parent[ch] = x;
                    visited[ch] = true;
                    q.push (ch);
                }
            }
        }
    }

    if (found) {
        std::vector<int> verts;
        int vert = n;

        while (parent[vert] != vert) {
            verts.push_back (vert);
            vert = parent[vert];
        }

        verts.push_back (vert);
        std::reverse (verts.begin(), verts.end());

        std::cout << verts.size() << '\n';

        for (auto x: verts)
            std::cout << x << ' ';
        std::cout << '\n';

    } else {
        std::cout << "IMPOSSIBLE\n";
    }
}
