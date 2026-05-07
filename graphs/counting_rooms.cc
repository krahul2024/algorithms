#include <iostream>
#include <queue>

void printPair (int i, int j) {
    printf ("%d, %d\n", i, j);
}

int main() {
    int n, m;
    scanf ("%d%d", &n, &m);

    int mat[n][m];
    bool vis[n][m];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char x;
            std::cin >> x;

            if (x == '.') mat[i][j] = 1;
            else mat[i][j] = 0;

            vis[i][j] = false;
        }
    }

    int rooms = 0;
    std::queue<std::pair<int, int>> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vis[i][j] || mat[i][j] != 1)
                continue;

            rooms += 1;
            q.push ({ i, j });

            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();

                if (x >= 0 && y >= 0 && x < n && y < m && mat[x][y] == 1 && !vis[x][y]) {
                    vis[x][y] = true;
                    q.push ({x, y+1});
                    q.push ({ x, y-1 });
                    q.push ({ x+1, y });
                    q.push ({ x-1, y });
                }
            }
        }
    }

    std::cout << rooms << '\n';
}
