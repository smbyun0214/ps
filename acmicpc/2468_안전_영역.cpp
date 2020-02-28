#include <iostream>
#include <cstring>
#include <set>

using namespace std;

int N;

bool cache[100][100];
int board[100][100];

bool inRange(int y, int x) {
    return 0 <= y && y < N && 0 <= x && x < N;
}

int countTerritory(int y, int x, int delta) {
    if (!inRange(y, x) || board[y][x] - delta <= 0 || cache[y][x])
        return 0;
    
    board[y][x] -= delta;
    cache[y][x] = true;
    
    int ret = 1;
    
    ret += countTerritory(y - 1, x, delta);
    ret += countTerritory(y + 1, x, delta);
    ret += countTerritory(y, x - 1, delta);
    ret += countTerritory(y, x + 1, delta);
    
    board[y][x] += delta;
    
    return ret;
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    memset(board, 0, sizeof(board));
    
    cin >> N;
    
    set<int> heights;
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> board[i][j];
            heights.insert(board[i][j]);
        }
    }
    
    int maxRet = 1;
    
    for (int delta :heights) {
        memset(cache, false, sizeof(cache));
        
        int ret = 0;
        for (int y = 0; y < N; ++y) {
            for (int x = 0; x < N; ++x) {
                if (!cache[y][x] && countTerritory(y, x, delta)) {
                    ++ret;
                }
            }
        }
        
        maxRet = max(maxRet, ret);
    }
    
    cout << maxRet << '\n';
    
    return 0;
}
