#include <iostream>
#include <cstring>

using namespace std;

int width, height;

int board[50][50];

bool inRange(int y, int x) {
    return 0 <= y && y < height && 0 <= x && x < width;
}

void growCabbage(int y, int x) {
    if (!inRange(y, x) || board[y][x] == 0)
        return;
    
    board[y][x] = 0;
    
    growCabbage(y - 1, x);
    growCabbage(y + 1, x);
    growCabbage(y, x - 1);
    growCabbage(y, x + 1);
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int T, k, x, y;
    
    cin >> T;
    
    while (T--) {
        memset(board, 0, sizeof(board));
        int ret = 0;
        
        cin >> width >> height >> k;

        while (k--) {
            cin >> x >> y;
            board[y][x] = 1;
        }
        
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                if (board[i][j] == 1) {
                    growCabbage(i, j);
                    ++ret;
                }
            }
        }
        
        cout << ret << '\n';
        
    }
    return 0;
}
