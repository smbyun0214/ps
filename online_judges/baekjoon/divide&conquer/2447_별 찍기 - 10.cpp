// https://www.acmicpc.net/problem/2447
// https://blog.naver.com/moonsoo5522/220706431458

#include <iostream>
#include <cstring>

using namespace std;

char board[2187][2187];

void filled(int y, int x, int size) {
    if (size == 1) {
        board[y][x] = '*';
        return;
    }
    
    int oneThird = size / 3;
    for (int dy = 0; dy < 3; ++dy) {
        for (int dx = 0; dx < 3; ++dx) {
            if (dy == 1 && dx == 1)
                continue;
            
            filled(y + dy * oneThird, x + dx * oneThird, oneThird);
        }
    }
}

int main (int argc, char *argv[]) {
    memset(board, 0, sizeof(board));
    
    int n;
    cin >> n;
    
    filled(0, 0, n);
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[i][j] != '*')
                cout << ' ';
            else
                cout << board[i][j];
        }
        cout << '\n';
    }
    
    return 0;
}
