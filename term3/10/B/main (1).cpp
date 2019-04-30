// poj 3020
// 相邻的"*"点之间有边
// 求最小边覆盖
#include <iostream>
#include <cstring>

using namespace std;

int star[45][15], link[405], v1, v2, numS, M, R, C;
bool edge[405][405], vis[405];

int dir_r[4] = {-1, 1, 0, 0};
int dir_c[4] = {0, 0, -1, 1};

bool dfs(int x) {
    for (int y = 1; y <= v2; y++) {
        if (edge[x][y] && !vis[y]) {
            vis[y] = true;
            if (link[y] == 0 || dfs(link[y])) {
                link[y] = x;
                return true;
            }
        }
    }
    return false;
}

void search() {
    for (int x = 1; x <= v1; x++) {
        memset(vis, 0, sizeof(vis));
        if (dfs(x))
            M++;
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        memset(star, 0, sizeof(star));
        memset(link, 0, sizeof(link));
        memset(edge, 0, sizeof(edge));
        numS = 0;
        M = 0;
        cin >> R >> C;
        char temp;
        for (int i = 1; i <= R; i++) {
            for (int j = 1; j <= C; j++) {
                cin >> temp;
                if (temp == '*') {
                    numS++;
                    star[i][j] = numS;
                }
            }
        }
        //       for (int i=1; i<=R; i++){
        //         for (int j=1; j<=C; j++){
        //           cout<<star[i][j]<<" ";
        //     }
        //   cout<<endl;
        //}
        for (int i = 1; i <= R; i++) {
            for (int j = 1; j <= C; j++) {
                if (!star[i][j])
                    continue;
                for (int k = 0; k < 4; k++) {
                    int tempX = i + dir_r[k];
                    int tempY = j + dir_c[k];
                    if (star[tempX][tempY]) {
                        edge[star[i][j]][star[tempX][tempY]] = true;
                    }
                }
            }
        }
        v1 = v2 = numS;
        search();
        cout << numS - M / 2 << endl;
    }
    return 0;
}