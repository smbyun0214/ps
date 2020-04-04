#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};

int height, width;

int distances[100][100];
char board[100][100];

bool inRange(int y, int x) {
    return 0 <= y && y < height && 0 <= x && x < width;
}

void travelMaze(int y, int x) {
    distances[y][x] = 1;
    
    queue<pair<int, int>> q;
    q.push(make_pair(y, x));
    
    while (!q.empty()) {
        pair<int, int> loc = q.front();
        q.pop();

        for (int direction = 0; direction < 4; ++direction) {
            int nextY = loc.first + dy[direction], nextX = loc.second + dx[direction];
            if (inRange(nextY, nextX) && distances[nextY][nextX] == -1 && board[nextY][nextX] == '1') {
                q.push(make_pair(nextY, nextX));
                distances[nextY][nextX] = distances[loc.first][loc.second] + 1;
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    memset(distances, -1, sizeof(distances));
    memset(board, 0, sizeof(board));
    
    cin >> height >> width;
    
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            cin >> board[i][j];
        }
    }
    
    travelMaze(0, 0);
    
    cout << distances[height - 1][width - 1] << '\n';
    
    return 0;
}
