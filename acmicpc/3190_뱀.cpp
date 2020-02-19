#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int N;
int board[100][100];

int direction = 0;
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

bool inRange(int y, int x) {
    return 0 <= y && y < N && 0 <= x && x < N && board[y][x] != -1;
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    memset(board, 0, sizeof(board));
    
    deque<pair<int, int>> snake;
    snake.push_front(make_pair(0, 0));
    board[0][0] = -1;
    
    char C;
    int K, X;
    cin >> N >> K;
    
    int appleY, appleX;
    
    while (K--) {
        cin >> appleY >> appleX;
        board[appleY - 1][appleX - 1] = 1;
    }
    
    cin >> K;
    
    vector<pair<int, char>> infos;
    
    while (K--) {
        cin >> X >> C;
        infos.push_back(make_pair(X, C));
    }
    
    vector<pair<int, char>>::iterator iter = infos.begin();
    
    int sec = 0;
    
    while (++sec) {
        if (iter != infos.end() && iter->first + 1 == sec) {
            if (iter->second == 'L') direction = (direction + 3) % 4;
            else direction = (direction + 1) % 4;
            ++iter;
        }
        
        pair<int, int> next = snake.front();
        next.first += dy[direction];
        next.second += dx[direction];
        
        if (!inRange(next.first, next.second)) break;
        
        if (board[next.first][next.second] == 0) {
            board[snake.back().first][snake.back().second] = 0;
            snake.pop_back();
        }
        
        board[next.first][next.second] = -1;
        snake.push_front(next);
    }
    
    cout << sec << '\n';
    
    return 0;
}
