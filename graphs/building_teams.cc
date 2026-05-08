#include <iostream>
#include <vector>
#include <queue>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> G(n+1);
    std::vector<int> vis (n+1, false);
    std::vector<int> colors (n+1, -1);

    for (int i = 0; i < m; i++) {
        int x, y;
        scanf ("%d%d", &x, &y);

        G[x].push_back (y);
        G[y].push_back (x);
    }

    bool is_bipartite = true;

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            std::queue<int> q;
            q.push (i);
            vis[i] = true;
            colors[i] = 0;

            while (!q.empty()) {
                auto x = q.front();
                q.pop();

                for (const auto& ch: G[x]) {
                    if (!vis[ch]) {
                        colors[ch] = colors[x] ^ 1;
                        vis[ch] = true;
                        q.push (ch);
                    } else if (vis[ch] && colors[ch] == colors[x]) {
                        is_bipartite = false;
                        break;
                    }
                }
            }
        }
    }

    if (is_bipartite) {
        for (int i = 1; i <= n; i++)
            std::cout << colors[i]+1 << ' ';

        std::cout << '\n';
    } else {
        std::cout << "IMPOSSIBLE\n";
    }
}
