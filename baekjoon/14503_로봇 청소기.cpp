// https://www.acmicpc.net/problem/14503

#include <iostream>
#include <cstring>

using namespace std;

int board[51][51];

int dy[] = { -1, 0, 1,  0 };
int dx[] = {  0, 1, 0, -1 };
int CLEANED = 2;

int width, height;

bool isWall(int y, int x) {
    return board[y][x] == 1;
}

int cleaningRoom(int y, int x, int direction) {
    board[y][x] = CLEANED;
    
    for (int i = 0; i < 4; ++i) {
        int nextDir = (4 + direction - (i + 1)) % 4;
        int nextY = y + dy[nextDir], nextX = x + dx[nextDir];
        
        if (!isWall(nextY, nextX) && board[nextY][nextX] != CLEANED) {
            return 1 + cleaningRoom(nextY, nextX, nextDir);
        }
    }
    
    int backDir = (direction + 2) % 4;
    if (!isWall(y + dy[backDir], x + dx[backDir]))
        return cleaningRoom(y + dy[backDir], x + dx[backDir], direction);
    
    return 1;
}


int main (int argc, char *argv[]) {
    memset(board, -1, sizeof(board));

    cin >> width >> height;
    
    int y, x, direction;
    cin >> y >> x >> direction;
    
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            cin >> board[i][j];
        }
    }
    
    cout << cleaningRoom(y, x, direction) << '\n';
    
    return 0;
}
