#include <iostream>

using namespace std;

const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};

int board[9][9];

bool inRange(int y, int x) {
    return 0 <= y && y < 9 && 0 <= x && x < 9;
}

bool isValid(int y, int x, int value) {
    for (int direction = 0; direction < 4; ++direction) {
        int i = 1;
        while (inRange(y + i * dy[direction], x + i * dx[direction])) {
            if (board[y + i * dy[direction]][x + i * dx[direction]] == value)
                return false;
            ++i;
        }
    }
    
    int baseY = y / 3, baseX = x / 3;
    
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (((3 * baseY + i) != y || (3 * baseX + j) != x)
                && board[3 * baseY + i][3 * baseX + j] == value)
                return false;
        }
    }
    
    return true;
}

bool sudoku() {
    int y = -1, x = -1;
    
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (board[i][j] == 0) {
                y = i;
                x = j;
                break;
            }
        }
        if (y != -1)
            break;
    }
    
    if (y == -1) return true;
    
    for (int i = 1; i <= 9; ++i) {
        if (isValid(y, x, i)) {
            board[y][x] = i;
            
            if (sudoku())
                return true;
            
            board[y][x] = 0;
        }
    }
    
    return false;
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cin >> board[i][j];
        }
    }
    
    sudoku();
    
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}

