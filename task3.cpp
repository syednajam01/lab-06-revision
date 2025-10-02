#include <iostream>
using namespace std;

int maze[4][4] = {
    {1,1,1,1},
    {0,0,0,1},
    {1,1,0,1},
    {1,1,1,1}
};

bool vis[4][4];

bool valid(int r, int c) {
    return r >= 0 && r < 4 && c >= 0 && c < 4 && maze[r][c] == 1 && !vis[r][c];
}

bool solve(int r, int c, int tr, int tc) {
    if (!valid(r,c)) return false;
    vis[r][c] = true;
    if (r == tr && c == tc) return true;
    int dr[4] = {-1,1,0,0};
    int dc[4] = {0,0,-1,1};
    for (int i = 0; i < 4; ++i) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (solve(nr, nc, tr, tc)) return true;
    }
    vis[r][c] = false;
    return false;
}

int main() {
    for (int i=0;i<4;i++)
        for (int j=0;j<4;j++) vis[i][j] = false;

    int sr = 2, sc = 0;
    int tr = 0, tc = 0;
    bool ok = solve(sr, sc, tr, tc);
    if (!ok) {
        cout << "no path found";
        return 0;
    }
    int out[4][4];
    for (int i=0;i<4;i++)
        for (int j=0;j<4;j++) out[i][j] = maze[i][j];

    for (int i=0;i<4;i++)
        for (int j=0;j<4;j++) if (vis[i][j]) out[i][j] = 2;

    cout << "path found (2 marks path):";
    for (int i=0;i<4;i++) {
        for (int j=0;j<4;j++) cout << out[i][j] << " ";
        cout << endl;
    }
    return 0;
}
