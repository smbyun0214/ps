#include <iostream>
#include <cstring>

using namespace std;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int board[500][500];
int cache[500][500];

int height, width;

bool inRange(int y, int x) {
    return 0 <= y && y < height && 0 <= x && x < width;
}

int downwardpath(int y, int x) {
    if (y == (height - 1) && x == (width - 1))
        return 1;
    
    int &ret = cache[y][x];
    if (ret != -1)
        return ret;
    
    ret = 0;
    
    for (int direction = 0; direction < 4; ++direction) {
        int nextY = y + dy[direction], nextX = x + dx[direction];
        if (inRange(nextY, nextX) && board[y][x] > board[nextY][nextX]) {
            ret += downwardpath(nextY, nextX);
        }
    }
    
    return ret;
}


int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    memset(cache, -1, sizeof(board));
    
    cin >> height >> width;
    
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            cin >> board[i][j];
        }
    }
    
    cout << downwardpath(0, 0) << '\n';
    
    return 0;
}
