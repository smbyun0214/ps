#include <iostream>
#include <cstring>

using namespace std;

const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};

int N;
bool visited[100][100];
char board[100][100];

bool inRange(int y, int x) {
    return 0 <= y && y < N && 0 <= x && x < N;
}

bool green(int val) {
    return val == 'G';
}

bool red(int val) {
    return val == 'R';
}

bool blue (int val) {
    return val == 'B';
}

bool redGreen(int val) {
    return val == 'R' || val == 'G';
}

void redGreenColor(int y, int x, bool (*trace)(int)) {
    for (int direction = 0; direction < 4; ++direction) {
        int nextY = y + dy[direction], nextX = x + dx[direction];
        if (inRange(nextY, nextX) && !visited[nextY][nextX] && trace(board[nextY][nextX])) {
            visited[nextY][nextX] = true;
            redGreenColor(nextY, nextX, trace);
        }
    }
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    memset(board, 0, sizeof(board));
    
    cin >> N;
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> board[i][j];
        }
    }
    
    int ret = 0, retRG = 0;
    
    memset(visited, 0, sizeof(visited));
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (!visited[i][j]) {
                if (board[i][j] == 'R')
                    redGreenColor(i, j, red);
                else if (board[i][j] == 'B')
                    redGreenColor(i, j, blue);
                else
                    redGreenColor(i, j, green);
                ++ret;
            }
                
        }
    }
    
    memset(visited, 0, sizeof(visited));
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (!visited[i][j]) {
                if (board[i][j] == 'R' || board[i][j] == 'G')
                    redGreenColor(i, j, redGreen);
                else
                    redGreenColor(i, j, blue);
                ++retRG;
            }
                
        }
    }
    
    cout << ret << ' ' << retRG << '\n';
    
    return 0;
}
