#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};

char board[12][6];
bool visited[12][6];

bool inRange(int y, int x) {
    return 0 <= y && y < 12 && 0 <= x && x < 6;
}

void falling(int y, const int x) {
    if (board[y][x] != '.') return;
    
    int nextY = y;
    
    while (inRange(--nextY, x)) {
        if (board[nextY][x] == '.') continue;
        swap(board[y][x], board[nextY][x]);
        --y;
    }
}

void PuyoPuyo(int y, int x, const char &puyo, vector<pair<int, int>> &group) {
    visited[y][x] = true;
    group.push_back(make_pair(y, x));
    
    for (int direction = 0; direction < 4; ++direction) {
        int nextY = y + dy[direction], nextX = x + dx[direction];
        if (inRange(nextY, nextX) && !visited[nextY][nextX] && board[nextY][nextX] == puyo) {
            PuyoPuyo(nextY, nextX, puyo, group);
        }
    }
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    memset(board, 0, sizeof(board));
    
    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < 6; ++j) {
            cin >> board[i][j];
        }
    }
    
    int ret = 0;
    bool isBoomb = true;
    
    while (isBoomb) {
        isBoomb = false;
        memset(visited, false, sizeof(visited));

        vector<vector<pair<int, int>>> groups;
        
        for (int i = 0; i < 12; ++i) {
            for (int j = 0; j < 6; ++j) {
                if (!visited[i][j] && board[i][j] != '.') {
                    vector<pair<int, int>> group;
                    
                    PuyoPuyo(i, j, board[i][j], group);
                    
                    if (group.size() >= 4) {
                        isBoomb = true;
                        groups.push_back(group);
                    }
                }
            }
        }
        
        for (vector<pair<int, int>> group : groups) {
            for (pair<int, int> loc : group)
                board[loc.first][loc.second] = '.';
        }
        for (vector<pair<int, int>> group : groups) {
            for (pair<int, int> loc : group)
                falling(loc.first, loc.second);
        }
        
        ++ret;
    }
    
    cout << ret - 1 << '\n';
    
    return 0;
}
