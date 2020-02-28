#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};

int height, width;

bool visited[300][300];
int board[2][300][300];

bool inRange(int y, int x) {
    return 0 <= y && y < height && 0 <= x && x < width;
}

void icebergSink(const int y, const int x, int frame) {
    visited[y][x] = true;
    
    int sink = 0;
    
    for (int direction = 0; direction < 4; ++direction) {
        const int nextY = y + dy[direction], nextX = x + dx[direction];
        if (inRange(nextY, nextX) && !visited[nextY][nextX] && board[frame % 2][nextY][nextX] == 0)
            ++sink;
    }
    
    board[(frame + 1) % 2][y][x] = ((board[frame % 2][y][x] - sink < 0) ? 0 : (board[frame % 2][y][x] - sink));
    
    for (int direction = 0; direction < 4; ++direction) {
        const int nextY = y + dy[direction], nextX = x + dx[direction];
        if (inRange(nextY, nextX) && !visited[nextY][nextX] && board[frame % 2][nextY][nextX] != 0) {
            icebergSink(nextY, nextX, frame % 2);
        }
    }
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    cin >> height >> width;
    
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            cin >> board[0][i][j];
        }
    }
    
    bool isSink = true;
    int year = 0;
    
    while (isSink) {
        isSink = false;
        int separation = 0;
        
        memset(visited, false, sizeof(visited));
        memset(board[(year + 1) % 2], 0, sizeof(board[(year + 1) % 2]));
        
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                if (board[year % 2][i][j] != 0 && !visited[i][j]) {
                    icebergSink(i, j, year);
                    ++separation;
                    isSink = true;
                }
            }
        }
        
        if (separation >= 2)
            break;
        
        ++year;
    }
    
    cout << (isSink == false ? 0 : year) << '\n';
    
    return 0;
}
