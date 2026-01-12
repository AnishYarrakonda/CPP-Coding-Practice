#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005; // grid size

int main() {
    int N;
    int sx, sy;
    cin >> N >> sx >> sy;

    bool haybale[MAXN][MAXN] = {0};
    int broken[MAXN][MAXN];
    memset(broken, -1, sizeof(broken));

    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        haybale[x][y] = true;
    }

    queue<pair<int,int>> q;
    broken[sx][sy] = 0;
    q.push({sx, sy});

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        int curCost = broken[x][y];

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx < 0 || nx > 1000 || ny < 0 || ny > 1000) continue;

            int cost = curCost + haybale[nx][ny];

            if (broken[nx][ny] == -1 || broken[nx][ny] > cost) {
                broken[nx][ny] = cost;
                q.push({nx, ny});
            }
        }
    }

    cout << broken[0][0] << "\n";

    return 0;
}