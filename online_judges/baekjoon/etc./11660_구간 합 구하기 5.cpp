// https://www.acmicpc.net/problem/11660

#include <iostream>
#include <cstring>

using namespace std;

int N, M;
int board[1025][1025];

int main (int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    memset(board, 0, sizeof(board));

    cin >> N >> M;

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            cin >> board[i][j];
            board[i][j] += board[i - 1][j] + board[i][j - 1] - board[i - 1][j - 1];
        }
    }
    
    int x1, y1, x2, y2;
    while (M--) {
        cin >> x1 >> y1 >> x2 >> y2;
        cout << board[x2][y2] - board[x2][y1 - 1] - board[x1 - 1][y2] + board[x1 - 1][y1 - 1] << '\n';
    }    
    return 0;
}
