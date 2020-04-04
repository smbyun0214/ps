#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int height, width;
bool board[100][100];

bool inRange(int y, int x) {
    return 0 <= y && y < height && 0 <= x && x < width;
}

int countTerritory(int y, int x) {
    if (!inRange(y, x) || board[y][x] == true)
        return 0;
    
    board[y][x] = true;
    
    int ret = 1;
    
    ret += countTerritory(y - 1, x);
    ret += countTerritory(y + 1, x);
    ret += countTerritory(y, x - 1);
    ret += countTerritory(y, x + 1);
    
    return ret;
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    memset(board, 0, sizeof(board));
    
    int K;
    cin >> height >> width >> K;
    
    int sx, sy, ex, ey;
    
    while (K--) {
        cin >> sx >> sy >> ex >> ey;
        
        for (int y = sy; y < ey; ++y) {
            for (int x = sx; x < ex; ++x) {
                board[y][x] = true;
            }
        }
    }
    
    vector<int> ret;
    
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (!board[i][j]) {
                ret.push_back(countTerritory(i, j));
            }
        }
    }
    
    sort(ret.begin(), ret.end());
    
    cout << ret.size() << '\n';
    
    for (int i : ret)
        cout << i << ' ';
    
    return 0;
}
