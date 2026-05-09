#include <iostream>
#include <queue>
#include <algorithm>

char get_dir_char (const std::pair<int, int>& p1, const std::pair<int, int>& p2) {
    char dir = '.';
    if (p2.first < p1.first) {
        dir = 'D';
    } else if (p2.first > p1.first) {
        dir = 'U';
    } else if (p2.second < p1.second) {
        dir = 'R';
    } else if (p2.second > p1.second) {
        dir = 'L';
    }

    return dir;
}

int main() {
    int n, m;
    std::cin >> n >> m;

    char matrix[n][m];
    bool vis[n][m];
    std::pair<int, int> parent[n][m];
    std::pair<int, int> start = { -1, -1 }, end = { -1, -1 };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> matrix[i][j];
            parent[i][j] = { -1, -1 };
            vis[i][j] = false;

            if (matrix[i][j] == 'A')
                start = { i, j };
        }
    }

    bool found = false;
    std::queue<std::pair<int, int>> q;
    q.push (start);
    vis[start.first][start.second] = true;
    parent[start.first][start.second] = start;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        if ((y == m-1 || x == n-1 || x == 0 || y == 0)&& matrix[x][y] == '.') {
            end = { x, y };
            found = true;
            break;
        } else {
            for (int k = -1; k <= 1; k += 2) {
                int xk = x+k, yk = y;
                if (xk >= 0 && yk >= 0 && xk < n && yk < m && matrix[xk][yk] == '.' && !vis[xk][yk]) {
                    vis[xk][yk] = true;
                    parent[xk][yk] = { x, y };
                    q.push ({ xk, yk });
                }

                xk = x, yk = y+k;
                if (xk >= 0 && yk >= 0 && xk < n && yk < m && matrix[xk][yk] == '.' && !vis[xk][yk]) {
                    vis[xk][yk] = true;
                    parent[xk][yk] = { x, y };
                    q.push ({ xk, yk });
                }
            }
        }
    }

    if (found) {
        std::pair<int, int> vert = end;
        std::string path;

        while (vert != parent[vert.first][vert.second]) {
            const char dir_char = get_dir_char (vert, parent[vert.first][vert.second]);
            path.push_back (dir_char);
            vert = parent[vert.first][vert.second];
        }

        std::reverse(path.begin(), path.end());
        std::cout << "YES\n" << path.size() << '\n' << path << '\n';
    } else {
        std::cout << "NO\n";
    }

}
