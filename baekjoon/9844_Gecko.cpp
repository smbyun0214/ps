// https://www.acmicpc.net/problem/9844

#include <iostream>
#include <cstring>

using namespace std;

int height, width;
int board[500][500];
int cache[500][500];

int solve(int y, int x) {
    if (y < 0 || height <= y || x < 0 || width <= x)
        return 0;
    
    int& ret = cache[y][x];
    if (ret != -1) return ret;
    
    return ret = board[y][x] + max(solve(y + 1, x - 1),
                               max(solve(y + 1, x),
                                   solve(y + 1, x + 1)));
}

int main (int argc, char *argv[]) {
    memset(cache, -1, sizeof(cache));
    
    cin >> height >> width;
    
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            cin >> board[i][j];
        }
    }
        
    int ret = 0;
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            ret = max(ret, solve(i, j));
        }
    }
        
    cout << ret;

    return 0;
}
