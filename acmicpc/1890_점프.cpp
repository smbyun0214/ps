#include <iostream>
#include <cstring>

using namespace std;

const int dy[] = {1, 0};
const int dx[] = {0, 1};

int N;
int board[100][100];
unsigned long long cache[100][100];

bool inRange(int y, int x) {
    return 0 <= y && y < N && 0 <= x && x < N;
}

unsigned long long jumping(int y, int x) {
    if (board[y][x] == 0) {
        if (y == N - 1 && x == N - 1)
            return 1;
        else
            return 0;
    }
    
    unsigned long long &ret = cache[y][x];
    if (ret != -1)
        return ret;
    
    ret = 0;
    
    const int weight = board[y][x];
    
    for (int direction = 0; direction < 2; ++direction) {
        int nextY = y + weight * dy[direction], nextX = x + weight * dx[direction];
        if (inRange(nextY, nextX)) {
            ret += jumping(nextY, nextX);
        }
    }
    
    return ret;
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    memset(board, 0, sizeof(board));
    memset(cache, -1, sizeof(cache));
    
    cin >> N;
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> board[i][j];
        }
    }
    
    cout << jumping(0, 0) << '\n';
    
    return 0;
}

