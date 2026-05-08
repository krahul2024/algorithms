#include <iostream>
#include <vector>
#include <queue>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> G(n+1);
    std::vector<int> vis (n+1, false);
    std::vector<int> team_nos (n+1, -1);
    std::vector<int> parent (n+1, -1);

    for (int i = 0; i < m; i++) {
        int x, y;
        scanf ("%d%d", &x, &y);

        G[x].push_back (y);
        G[y].push_back (x);
    }

    bool is_cyclic = false;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            std::queue<int> q;
            q.push (i);
            vis[i] = true;
            parent[i] = -1;
            team_nos[i] = 1;

            while (!q.empty()) {
                auto x = q.front();
                q.pop();

                for (const auto& ch: G[x]) {
                    if (vis[ch] && parent[ch] == parent[x]) {
                        is_cyclic = true;
                        break;
                    }
                    if (!vis[ch]) {
                        parent[ch] = x;
                        vis[ch] = true;
                        q.push (ch);

                        team_nos[ch] = team_nos[x] == 1 ? 2: 1;
                    }

                }
            }
        }
    }

    if (!is_cyclic) {
        for (int i = 1; i <= n; i++)
            std::cout << team_nos[i] << ' ';

        std::cout << '\n';
    } else {
        std::cout << "IMPOSSIBLE\n";
    }
}
