#include <algorithm>
#include <iostream>
#include <queue>

bool is_same_pair (const std::pair<int, int>& p1, const std::pair<int, int>& p2) {
    return p1.first == p2.first && p1.second == p2.second;
}

bool is_valid (const int x, const int y, const int n, const int m) {
    return (x >= 0 && y >= 0 && x < n && y < m);
}

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

    std::pair<int, int> start, end;
    char matrix [n][m];
    bool vis[n][m];
    std::pair<int, int> parent[n][m];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> matrix[i][j];
            vis[i][j] = false;

            if (matrix[i][j] == 'A')
                start = {i, j};
            if (matrix[i][j] == 'B')
                end = {i, j};
        }
    }

    std::queue<std::pair<int, int>> q;
    q.push (start);
    parent[start.first][start.second] = start;
    vis[start.first][start.second] = true;

    bool found = false;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        if (matrix[x][y] == 'B') {
            found = true;
            break;
        } else {
            for (int k = -1; k <= 1; k += 2) {
                int xk = x, yk = y+k;
                if (is_valid (xk, yk, n, m) && !vis[xk][yk] && matrix[xk][yk] != '#') {
                    vis[xk][yk] = true;
                    parent[xk][yk] = { x, y };
                    q.push ({ xk, yk });
                }

                xk = x+k, yk = y;
                if (is_valid (xk, yk, n, m) && !vis[xk][yk] && matrix[xk][yk] != '#') {
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
        while (!is_same_pair (parent[vert.first][vert.second], vert)) {
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
