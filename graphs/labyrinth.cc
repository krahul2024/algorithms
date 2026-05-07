#include <iostream>
#include <queue>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::pair<int, int> start, end;
    char matrix [n][m];
    bool vis[n][m];
    int dist[n][m];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> matrix[i][j];
            vis[i][j] = false;
            dist[i][j] = 0;

            if (matrix[i][j] == 'A')
                start = {i, j};
            if (matrix[i][j] == 'B')
                end = {i, j};
        }
    }

    std::queue<std::pair<std::pair<int, int>, std::pair<int, int>>> q;
    q.push ({ start, { -1, -1 }});

    while (!q.empty()) {
        auto [idx, dist_par] = q.front();
        q.pop();

        auto [x, y] = idx;
        if (x >= 0 && y >= 0 && x < n && y < m && matrix[x][y] != '#' && !vis[x][y]) {
            vis[x][y] = true;
            path.push_back(chr);
            printf ("[%d][%d]=%c: %c --> ", x, y, chr, matrix[x][y]);

            if (matrix[x][y] == 'B') {
                found = true;
                break;
            } else {
                q.push ({{ x, y+1 }, 'R'});
                q.push ({{ x, y-1 }, 'L'});
                q.push ({{ x+1, y }, 'D'});
                q.push ({{ x-1, y }, 'U'});
            }
        }
    }

    printf ("%s\n%zu\n%s\n", (found? "YES": "NO"), path.size(), path.data());
}
