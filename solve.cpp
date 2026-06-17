#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

int n, m;
vector<string> maze;
int sy, sx, ty, tx;

int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

bool inside(int y, int x)
{
    return y >= 0 && y < n && x >= 0 && x < m && maze[y][x] != '#';
}


struct Node {
    int y, x, dir, cnt;
};

int bfs() {
    int NM = n * m;
    static int dist[200000][4][3];
    for (int id = 0; id < NM; id++)
        for (int d = 0; d < 4; d++)
            for (int c = 0; c < 3; c++)
                dist[id][d][c] = INF;
    queue<Node> q;
    for (int d = 0; d < 4; d++) {
        int ny = sy + dy[d], nx = sx + dx[d];
        if (!inside(ny, nx)) continue;
        int id = ny * m + nx;
        dist[id][d][0] = 1;
        q.push({ny, nx, d, 1});
    }
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        int id = cur.y * m + cur.x;
        int curDist = dist[id][cur.dir][cur.cnt - 1];
        if (cur.y == ty && cur.x == tx) {
            return curDist;
        }
        for (int d = 0; d < 4; d++) {
            int new_cnt = (d == cur.dir ? cur.cnt + 1 : 1);
            if (new_cnt > 3) continue;
            int ny = cur.y + dy[d], nx = cur.x + dx[d];
            if (!inside(ny, nx)) continue;
            int nid = ny * m + nx;
            if (dist[nid][d][new_cnt - 1] > curDist + 1) {
                dist[nid][d][new_cnt - 1] = curDist + 1;
                q.push({ny, nx, d, new_cnt});
            }
        }
    }
    return -1;
}

int main()
{
    cin >> n >> m;
    maze.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> maze[i];
        for (int j = 0; j < m; j++)
        {
            if (maze[i][j] == 'S')
            {
                sy = i;
                sx = j;
            }
            else if (maze[i][j] == 'T')
            {
                ty = i;
                tx = j;
            }
        }
    }
    int answer = bfs();
    cout << answer << "\n";
    return 0;
}