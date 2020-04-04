#include <iostream>
#include <cstring>

using namespace std;

const int dy[] = {0, 1, 1};
const int dx[] = {1, 0, 1};

int height, width;
int candy[1000][1000];
int board[1000][1000];

bool inRange(int y, int x) {
    return 0 <= y && y < height && 0 <= x && x < width;
}

int movingMaze(int y, int x) {
    int &ret = candy[y][x];
    if (ret != -1)
        return ret;
    
    ret = board[y][x];
    
    for (int direction = 0; direction < 3; ++direction) {
        int nextY = y + dy[direction], nextX = x + dx[direction];
        
        if (inRange(nextY, nextX)) {
            ret = max(ret, board[y][x] + movingMaze(nextY, nextX));
        }
    }
    
    return ret;
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    memset(candy, -1, sizeof(candy));
    memset(board, 0, sizeof(board));
    
    cin >> height >> width;
    
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            cin >> board[i][j];
        }
    }
    
    cout << movingMaze(0, 0) << '\n';
    
    return 0;
}
