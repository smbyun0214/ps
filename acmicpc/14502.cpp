#include <iostream>
#include <cstring>

using namespace std;

int H, W;
int board[8][8], board2[8][8];

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

bool inRange(int y, int x) {
    return 0 <= y && y < H && 0 <= x && x < W;
}

void resetBoard() {
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (board2[i][j] != 1)
                board2[i][j] = board[i][j];
        }
    }
}

void spreadOut(int y, int x, int delta) {
    if (!inRange(y, x))
        return;
    
    board2[y][x] = delta;
    
    for (int direction = 0; direction < 4; ++direction) {
        int nextY = y + dy[direction], nextX = x + dx[direction];
        if (board2[nextY][nextX] == 0) {
            
            spreadOut(nextY, nextX, delta);
        }
    }
}

void spreadOutVirus() {
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (board2[i][j] == 2)
                spreadOut(i, j, 2);
        }
    }
}

int countPlaces() {
    int ret = 0;

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (board2[i][j] == 0)
                ++ret;
        }
    }
    
    return ret;
}

void setWall(int y, int x, int delta) {
    board2[y][x] = delta;
}

int maxPlaces(int lastY, int lastX, int wall) {
    if (wall == 3) {
        spreadOutVirus();
        return countPlaces();
    }

    int ret = 0;
    
    for (int i = lastY; i < H; ++i) {
        if (i != lastY) lastX = 0;
        
        for (int j = lastX; j < W; ++j) {
            if (board2[i][j] == 0) {
                setWall(i, j, 1);
                
                ret = max(ret, maxPlaces(i, j, wall + 1));
                
                resetBoard();
                setWall(i, j, 0);
            }
        }
    }
    
    return ret;
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    memset(board, 0, sizeof(board));
    memset(board2, 0, sizeof(board2));
    
    cin >> H >> W;
    
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> board[i][j];
        }
    }
    
    resetBoard();
    
    cout << maxPlaces(0, 0, 0) << '\n';
    
    return 0;
}
