#include <iostream>
#include <cstring>

using namespace std;

const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};

int height, width, maxRet;

char board[20][20];
bool used[26];

bool inRange(int y, int x) {
    return 0 <= y && y < height && 0 <= x && x < width;
}

int maxStep(int y, int x) {
    used[board[y][x] - 'A'] = true;
    
    int ret = 1;
    
    for (int direction = 0; direction < 4; ++direction) {
        int nextY = y + dy[direction], nextX = x + dx[direction];
        if (inRange(nextY, nextX) && !used[board[nextY][nextX] - 'A']) {
            ret = max(ret, 1 + maxStep(nextY, nextX));
        }
    }
    
    used[board[y][x] - 'A'] = false;
    maxRet = max(maxRet, ret);
    
    return ret;
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    memset(board, 0, sizeof(board));
    memset(used, 0, sizeof(used));
    
    cin >> height >> width;
    
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            cin >> board[i][j];
        }
    }
    
    maxRet = 0;
    cout << maxStep(0, 0) << '\n';
    
    return 0;
}
