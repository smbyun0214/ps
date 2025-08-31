// https://www.acmicpc.net/problem/2448
// https://ssu-gongdoli.tistory.com/79

#include <iostream>
#include <cstring>

using namespace std;

char star[3][6] = {
    "  *  ",
    " * * ",
    "*****"
};

char board[6144][6144];
int n = 6;

void printStar(int y, int x, int size) {
    if (size == 1) {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 5; ++j) {
                board[y + i][x + j] = star[i][j];
            }
        }
        return;
    }
    
    printStar(y, x + 3 * size / 2, size / 2);
    printStar(y + 3 * size / 2, x, size / 2);
    printStar(y + 3 * size / 2, x + 3 * size, size / 2);
}

int main (int argc, char *argv[]) {
    memset(board, 0, sizeof(board));
    
    cin >> n;
    
    printStar(0, 0, n / 3);
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2 * n; ++j) {
            if (board[i][j] == '*')
                cout << '*';
            else
                cout << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}
