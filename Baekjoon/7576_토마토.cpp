#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};

int width, height;

bool visited[1000][1000];
int days[1000][1000];
int board[1000][1000];

queue<pair<int, int>> q;

bool inRange(int y, int x) {
    return 0 <= y && y < height && 0 <= x && x < width;
}

void becomeRipe() {
    while (!q.empty()) {
        pair<int, int> now = q.front();
        q.pop();
        
        visited[now.first][now.second] = true;
        
        if (board[now.first][now.second] == 1)
            days[now.first][now.second] = 0;
        
        for (int direction = 0; direction < 4; ++direction) {
            int nextY = now.first + dy[direction], nextX = now.second + dx[direction];
            if (inRange(nextY, nextX) && !visited[nextY][nextX] && board[nextY][nextX] != -1) {
                visited[nextY][nextX] = true;
                q.push(make_pair(nextY, nextX));
                days[nextY][nextX] = days[now.first][now.second] + 1;
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    memset(board, 0, sizeof(board));
    
    cin >> width >> height;
    
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            cin >> board[i][j];
            if (board[i][j] == 1)
                q.push(make_pair(i, j));
            
        }
    }
    
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            days[i][j] = height * width;
        }
    }
    
    becomeRipe();
    
    int ret = 0;
    
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (board[i][j] != -1)
                ret = max(ret, days[i][j]);
        }
    }
    
    cout << (ret == height * width ? -1 : ret) << '\n';
    
    return 0;
}
