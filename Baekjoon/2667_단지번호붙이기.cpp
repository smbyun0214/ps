#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int board[25][25];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

bool inRange(int y, int x) {
    return 0 <= y && y < N && 0 <= x && x < N;
}
int houseCount(int y, int x) {
    if (!inRange(y, x) || board[y][x] == 0)
        return 0;
    
    int ret = 1;
    
    for (int direction = 0; direction < 4; ++direction) {
        int nextY = y + dy[direction], nextX = x + dx[direction];
        
        board[y][x] = 0;
        ret += houseCount(nextY, nextX);
    }
    
    return ret;
}

vector<int> houseCountAll() {
    vector<int> ret;
    
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            if (board[y][x]) {
                ret.push_back(houseCount(y, x));
            }
        }
    }
    
    return ret;
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    cin >> N;
    
    char c;
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> c;
            board[i][j] = c - '0';
        }
    }
    
    vector<int> ret = houseCountAll();
    
    sort(ret.begin(), ret.end());
    
    cout << ret.size() << '\n';
    for (int i : ret) {
        cout << i << '\n';
    }
    
    return 0;
}
