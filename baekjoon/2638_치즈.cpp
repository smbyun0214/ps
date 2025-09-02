// https://www.acmicpc.net/problem/2638

#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int N, M;
int board[100][100];
bool visited[100][100];

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

bool inRange(int y, int x) {
    return 0 <= y && y < N && 0 <= x && x < M;
}

void init() {
    memset(visited, false, sizeof(visited));

    for (int i = 0; i < N; ++i) {
        if (board[i][0] == 0) {
            visited[i][0] = true;
        }
        if (board[i][M - 1] == 0) {
            visited[i][M - 1] = true;
        }
    }
    for (int i = 0; i < M; ++i) {
        if (board[0][i] == 0) {
            visited[0][i] = true;
        }
        if (board[N - 1][i] == 0) {
            visited[N - 1][i] = true;
        }
    }
}

void setVisited() {
    queue<pair<int, int> > q;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (visited[i][j]) {
                q.push(make_pair(i, j));
            }
        }
    }

    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();

        int y = p.first;
        int x = p.second;

        for (int direction = 0; direction < 4; ++direction) {
            int nextY = y + dy[direction], nextX = x + dx[direction];
            if (inRange(nextY, nextX) && !visited[nextY][nextX] && board[nextY][nextX] == 0) {
                visited[nextY][nextX] = true;
                q.push(make_pair(nextY, nextX));
            }
        }
    }
}

bool isMeltedCheese(int y, int x) {
    int touch = 0;
    for (int direction = 0; direction < 4; ++direction) {
        int nextY = y + dy[direction], nextX = x + dx[direction];
        if (inRange(nextY, nextX) && visited[nextY][nextX]) {
            ++touch;
        }
    }
    return touch >= 2;
}

bool progress() {
    bool isMelted = false;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (board[i][j] == 1 && isMeltedCheese(i, j)) {
                board[i][j] = 0;
                isMelted = true;
            }
        }
    }

    return isMelted;
}

int main (int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> board[i][j];
        }
    }

    init();

    int ret = 0;
    while (true) {
        setVisited();
        if (!progress()) {
            break;
        }
        ++ret;
    }

    cout << ret << '\n';

    return 0;
}
