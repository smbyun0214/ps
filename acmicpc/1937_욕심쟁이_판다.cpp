#include <iostream>
#include <cstring>

using namespace std;

const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};

int N;
int board[500][500];
int cache[500][500];

bool inRange(int y, int x) {
    return 0 <= y && y < N && 0 <= x && x < N;
}

int routes(int y, int x) {
    int &ret = cache[y][x];
    if (ret != -1)
        return ret;
    
    ret = 0;
    
    for (int direction = 0; direction < 4; ++direction) {
        int nextY = y + dy[direction], nextX = x + dx[direction];
        if (inRange(nextY, nextX) && board[y][x] < board[nextY][nextX]) {
            ret = max(ret, 1 + routes(nextY, nextX));
        }
    }
    
    return ret;
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    memset(cache, -1, sizeof(cache));
    
    cin >> N;
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> board[i][j];
        }
    }
    
    int ret = 0;
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            ret = max(ret, routes(i, j));
        }
    }
    
    cout << ret + 1 << '\n';
    
    return 0;
}
