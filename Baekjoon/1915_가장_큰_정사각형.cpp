#include <iostream>
#include <cstring>

using namespace std;

const int dy[] = {-1, -1, 0};
const int dx[] = {0, -1, -1};
const int INF = 987654321;

int height, width;

int board[1001][1001];

bool inRange(int y, int x) {
    return 0 <= y && y < height && 0 <= x && x < width;
}

int rectangle(int y, int x) {
    int &ret = board[y][x];
    
    ret = INF;
    
    for (int direction = 0; direction < 3; ++direction)
        ret = min(ret, board[y + dy[direction]][x + dx[direction]]);
    
    ret += 1;
    
    return ret;
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    memset(board, 0, sizeof(board));
    
    char c;
    cin >> height >> width;
    
    for (int i = 1; i <= height; ++i) {
        for (int j = 1; j <= width; ++j) {
            cin >> c;
            board[i][j] = c - '0';
        }
    }
    
    int ret = 0;
    
    for (int i = 1; i <= height; ++i) {
        for (int j = 1; j <= width; ++j) {
            if (board[i][j] != 0)
                ret = max(ret, rectangle(i, j));
        }
    }
    
    cout << ret * ret << '\n';
    
    return 0;
}
