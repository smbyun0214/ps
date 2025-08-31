// https://www.acmicpc.net/problem/14430

#include <iostream>
#include <cstring>

using namespace std;

int N, M;
int board[300][300];
int cache[300][300];

bool inRange(int y, int x) {
    return 0 <= y && y < N && 0 <= x && x < M;
}

int solve(int y, int x) {
    if (!inRange(y, x)) return 0;
    
    int& ret = cache[y][x];
    if (ret != -1) return ret;
    
    return ret = board[y][x] + max(solve(y + 1, x), solve(y, x + 1));
    
}

int main (int argc, char *argv[]) {
    memset(cache, -1, sizeof(cache));
    
    cin >> N >> M;
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> board[i][j];
        }
    }
    
    cout << solve(0, 0);
    
    return 0;
}
